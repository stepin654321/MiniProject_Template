#include"test.h"


int main()
{
    FILE *fp = fopen("data.csv", "r");
    if(!fp)
    {
        printf("Error occurred");
        return 0 ;
    }
    char buff[1024];
    int row_count = 0;
    int field_count = 0;
    dict values[999];
    int i = 0;
    while(fgets(buff, 1024, fp))
    {
        field_count = 0;
        row_count++;
        if(row_count == 1)
            continue;
        char *field = strtok(buff, ",");
        while(field)
        {
            if(field_count == 0)
                strcpy(values[i].name, field);

            if(field_count == 1)
                strcpy(values[i].email_id, field);

            if(field_count == 2)
                strcpy(values[i].github_link, field);

            field = strtok(nullptr, ",");
            field_count++;
        }
        i++;
    }
    fclose(fp);
    printValues(values);
    return 0;
}
