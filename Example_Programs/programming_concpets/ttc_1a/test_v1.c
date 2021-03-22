#include<stdio.h>
#include "header_def.h"
#include "unity.h"


/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_div(void){
    int real_a=5;
    int img_b=1;
    int real_c=2;
    int img_d=3;
    complex_num a,b;
    a.real = real_a;
    a.img = img_b;
    b.real = real_c;
    b.img = img_d;
    TEST_ASSERT_EQUAL(0, div(a,b));
}; // 5,1,2,3 -- 0

void test_sum(void){
    int real_a=5;
    int img_b=2;
    int real_c=1;
    int img_d=1;
    complex_num a,b;
    a.real = real_a;
    a.img = img_b;
    b.real = real_c;
    b.img = img_d;
    TEST_ASSERT_EQUAL(9, sum(a,b));
} // pass 5,2 ,1,1 --> 6+3 = 9

void test_sub(void){
    int real_a=5;
    int img_b=3;
    int real_c=1;
    int img_d=2;
    complex_num a,b;
    a.real = real_a;
    a.img = img_b;
    b.real = real_c;
    b.img = img_d;
    TEST_ASSERT_EQUAL(5, sub(a,b));
}; // 5 3 1 2 -- 5
void test_mul(void){
    int real_a=1;
    int img_b=2;
    int real_c=3;
    int img_d=4;
    complex_num a,b;
    a.real = real_a;
    a.img = img_b;
    b.real = real_c;
    b.img = img_d;
    TEST_ASSERT_EQUAL(5, mul(a,b));
};  // 1 2 3 4 -- 5

int main(){
    
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_sum);
    RUN_TEST(test_div);
    RUN_TEST(test_sub);
    RUN_TEST(test_mul);

 
    /* Close the Unity Test Framework */
    return UNITY_END();


//     complex_num a,b,c;

//     int choice;
//     while(1)
//   {
//         printf("Press 1 to add two complex numbers.\n");
//         printf("Press 2 to subtract two complex numbers.\n");
//         printf("Press 3 to multiply two complex numbers.\n");
//         printf("Press 4 to divide two complex numbers.\n");
//         printf("Press 5 to exit.\n");
//         printf("Enter your choice\n");
//         scanf("%d", &choice);

//         if(choice == 5){
//             exit(0);
//         }

//          if (choice >= 1 && choice <= 4)
//     {
//       printf("Enter a and b where a + ib is the first complex number.");
//       printf("\na = ");
//       scanf("%d", &a.real);
//       printf("b = ");
//       scanf("%d", &a.img);
//       printf("Enter c and d where c + id is the second complex number.");
//       printf("\nc = ");
//       scanf("%d", &b.real);
//       printf("d = ");
//       scanf("%d", &b.img);
//     }
//     if(choice == 1){
//         int res = sum(a,b);
//     }
//     if(choice == 2){
//         int res = sub(a,b);
//     }
//     if(choice == 3){
//         int res = mul(a,b);
//     }
//     if(choice == 4){
//         int res = div(a,b);
//     }
  
  
  
//   } // while end


//     return 0;

    //gcc -I inc src/c_div.c src/c_mul.c src/c_sub.c src/c_sum.c test_v1.c -o test_v1.exe

    //gcc -I inc -I unity unity/unity.c src/c_div.c src/c_mul.c src/c_sub.c src/c_sum.c test_v1.c -o test_v1.exe
}