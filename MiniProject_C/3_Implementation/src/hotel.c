#include <hotel.h>



#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>




struct room
{
    char name[100];
    int num;
    int fd,fm,fy,td,tm,ty;
    char status[20];
}a,a2;



//constructing the structure for the user credentials
struct details
{
    char name[100];
    char password[100];
}user;




int available(char name2[],int room,char status2[])
{
        FILE *q;
        int f=0,flag1=0,i=0,j,g=0;
        q=fopen("database","r");

        do
        {

           fscanf(q,"%s %d %s",a2.name,&a2.num,a2.status);
          // fscanf(q,"%s : Room_no : %d : %s",a2.name,&a2.num,a2.status);

           //fscanf(q,"%s : Room no. %d %s",a2.name,&a2.num,a2.status);
           //fscanf(q,"%d",&a2.num);
            printf("read from database%s\n",a2.name);
             printf("read from database%d\n",a2.num);
            printf("read from for loop%d\n",room);




            if(a2.num==room){
                   fclose(q);
                   return 0;

                     }
        }
        while(!feof(q));

        fclose(q);
        return 1;

}





//checking the room if its available or not, if available then alloted
int allot(char name1[],int type,char status1[])
{
    int i;
    for(i=(type*100)+1;i<(type*100)+10;i++)
    {
        if(available(name1,i,status1)==1)
        {
            return i;
        }
    }
    return 0;
}






//function to get the choice of "valid" type of room that the user wants
int getchoice()
{
    int choice=0;
    printf("\nEnter Type of Room(Type 1 to 6):");
    scanf("%d",&choice);
    if(choice>6 || choice<1)
    {
        printf("\nChoice you entered is invalid.Enter a valid choice.\n\n");
        return 0;
    }
    else
    {
        return choice;
    }
}



//function to give the user an another chance of trying some other type of room since it may not be available
int printroom(int choice)
{
    int choice1,num=0;
    num=allot(a.name,choice,a.status);
    if(num==0)
    {
        int cont;
        printf("\nSorry No room available of this type!\n\nEnter 1 to try another type, 0 to exit to main menu: ");
        scanf("%d",&cont);
        if (cont == 1)
        {
            printf("\n\nTry another type: ");
            choice1 = getchoice();
            printroom(choice1);
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return num;
    }
}





//booking a room
void book(){
    login();
    FILE *p,*q;
    int b,n,i,count=0,flag1;
    long long int fare = 0;
    int price[6]={2500,2000,3500,3000,4500,5000};
    printf("\n\nHere are the type of rooms and their maximum occupancy with tariffs:\n  Type         Max Occupancy    Tariff(/Night)\n");
        printf("1.Single AC          1             Rs.2500\n2.Non AC Single      1             Rs.2000\n3.Double AC          2             Rs.3500\n4.Double Non AC      2             Rs.3000\n5.Duplex             4             Rs.4500\n6.Suite              5             Rs.5000\n");
        printf("\nEnter Number of Rooms you want:");
        scanf("%d",&n);
        int choice;
        while(1)
        {
	    choice=getchoice();
            while(choice==0)
            {
            choice=getchoice();
            }
       
            a.num=printroom(choice);
            if (a.num == -2)
            {
                printf("\nTotal fare is Rs.%lld\n\n",fare);
                return;
            }
            count++;
            printf("\nHey %s, your booking is successful and your room number is %d!!\n\n",a.name,a.num);

            strncpy(a.status,"Booked",sizeof(a.status));
            p=fopen("database","a");
            fprintf(p,"%s %d %s\n",a.name,a.num,a.status);
            //fprintf(p,"%s : Room_no : %d : %s\n",a.name,a.num,a.status);
            //fprintf(p,"%s : Room no. %d %s\n",a.name,a.num,a.status);
            //fprintf(p,"%d\n",a.num);
            fclose(p);
            if(count==n)
            {
                break;
            }
        }

    }




void display()
{
    int ctr,i;
    int flag = 0,flag1,control = 0;
    FILE *q,*newdata,*pass;
    char nam[100];
    char ipassword[100];
    printf("\nEnter Name(Without spaces): ");

    //checking if the name has space in between or not
    scanf(" %[^\n]s",nam);
    for(i = 0; i<strlen(nam); i++)
    {
		if(nam[i] == ' ')
        {
        	printf("Invalid Username\n\n");
        	return;
        }
    }
    printf("Enter password(Without spaces): ");

    //checking if the password has space in between or not
    scanf(" %[^\n]s",ipassword);
    for(i = 0; i<strlen(ipassword); i++)
    {
	    if(ipassword[i] == ' ')
        {
        	printf("Invalid Password\n\n");
        	return;
       	}
    }
    pass = fopen("user credentials","r");

    //Checking if the username and password are correct
    do
    {
        fscanf(pass,"%s : %s",user.name,user.password);
        if(strcmp(user.name,nam) == 0 && strcmp(user.password,ipassword) == 0)
        {
            flag1 = 1;
        }
    }
    while( !feof(pass) );
    fclose(pass);

    //printing all the bookings made in the name of the user
    if(flag1 == 1)
    {
        int cntrl = 0;
        q = fopen("database","r");
        do
        {
           fscanf(q,"%s %d %s",a.name,&a.num,a.status);
           if(feof(q))
            {
               break;
            }
            if(strcmp(a.name,nam) == 0)
            {

                control++;
                flag = 1;
                printf("%d. %s %d %s\n",control,a.name,a.num,a.status);
            }
        }
        while( !feof(q) );

        if (flag == 0)
        {
           printf("Booking Not Found\n\n");
           fclose(q);
           return;
        }
        fclose(q);
    }
    else
    {
        printf("Invalid username or password\n");
    }
}






void cancel()
{
    int ctr,i;
    int flag = 0,flag1,control = 0;
    FILE *q,*newdata,*pass;
    char nam[100];
    char ipassword[100];
    printf("\nEnter Name(Without spaces): ");

    //checking if the name has space in between or not
    scanf(" %[^\n]s",nam);
    for(i = 0; i<strlen(nam); i++)
    {
		if(nam[i] == ' ')
        {
        	printf("Invalid Username\n\n");
        	return;
        }
    }
    printf("Enter password(Without spaces): ");

    //checking if the password has space in between or not
    scanf(" %[^\n]s",ipassword);
    for(i = 0; i<strlen(ipassword); i++)
    {
	    if(ipassword[i] == ' ')
        {
        	printf("Invalid Password\n\n");
        	return;
       	}
    }
    pass = fopen("user credentials","r");

    //Checking if the username and password are correct
    do
    {
        fscanf(pass,"%s : %s",user.name,user.password);
        if(strcmp(user.name,nam) == 0 && strcmp(user.password,ipassword) == 0)
        {
            flag1 = 1;
        }
    }
    while( !feof(pass) );
    fclose(pass);

    //printing all the bookings made in the name of the user
    if(flag1 == 1)
    {
        int cntrl = 0;
        q = fopen("database","r");
        do
        {
           fscanf(q,"%s %d %s",a.name,&a.num,a.status);
           if(feof(q))
            {
               break;
            }
            if(strcmp(a.name,nam) == 0)
            {

                control++;
                flag = 1;
                printf("%d. %s %d %s\n",control,a.name,a.num,a.status);
            }
        }
        while( !feof(q) );

        if (flag == 0)
        {
           printf("Booking Not Found\n\n");
           fclose(q);
           return;
        }
        fclose(q);
        int flag2 = 0;
        int loop;

        //Asking the user how many bookings(in no.) he wants to cancel
        do
        {
            flag2 = 0;
            printf("How many bookings do you want to cancel: ");
            scanf("%d",&loop);
            if(loop>control)
            {
                printf("Invalid number of cancellatons\n\n");
                flag2 = 1;
                int choice;
                printf("Do you want to continue with cancellation? Enter 1 to continue, 0 to return to main menu: ");
                scanf("%d",&choice);
                if (choice == 0)
                {
                    return;
                }
            }
        }
        while(flag2 == 1);

        //Asking him the serial no. of the booking which he wants to cancel and then cancelling it if the serial no. is valid
        for(int i = 0; i<loop; i++)
        {
                printf("\nWhich room number booking do you want to cancel: ");
                scanf("%d",&ctr);
                q = fopen("database","r");
                newdata = fopen("newdatabase","w");
                if(newdata==NULL)
                   printf("file not exist");
                else
                   printf("file exists");




             while(fscanf(q,"%s %d %s",a.name,&a.num,a.status)== 3){

                if (ctr == a.num)
                   continue;
               else
                   fprintf(newdata,"%s %d %s\n",a.name,a.num,a.status);


             }



            fclose(q);
            fclose(newdata);
            remove("database");
            rename("newdatabase","database");
            printf("\n\nThe Customer is successfully removed....");


        }
    }
    else
    {
        printf("Invalid username or password\n");
    }
}























