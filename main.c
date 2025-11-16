/*The Employee Payroll Management System*/

#include<stdio.h>
#include<string.h>
#include "employee.h"


int check_admin()
{
    int l;
    char name[25], pass[15];
    printf("Please Enter Admin Username\n");
    fgets(name,sizeof(name),stdin);
    l = strlen(name);
    if(name[l-1] == '\n')
    name[l-1] = '\0';
    printf("Please Enter Admin Password\n");
    scanf("%s",pass);
    if(strcmp(name,"Admin Ishita") == 0 && strcmp(pass,"ishi.6") == 0)
    return 1;
    else
    return 0;
}

void showEmployee(FILE *p)
{
    struct employee E;
    int c = 0;
    rewind(p);
    while(fread(&E, sizeof(E),1,p) == 1){
        printf("Emplpoyee Name :- %s\n",E.name);
        c++;
    }
    if(c == 0)
    printf("No Employee Data Stored\n");


}

int main()
{
    int v = check_admin();
    if(v==1)
    {
        FILE *P = fopen("data.txt","rb");
        if(P!= NULL)
        {
            printf("--Employees Stored are--\n");
            showEmployee(P);
            fclose(P);
        }
        else
        printf("--No Employee Data is Stored--\n");
    int ch;
    while(1){
        printf("Press 1 to ADD EMPLOYEE\n");
        printf("Press 2 to DELETE EMPLOYEE\n");
        printf("Press 3 to CHECK CREDENTIALS AND DISPLAY RECORD\n");
        printf("Press 4 to EXIT FROM EMPLOYEE PAYROLL MANAGEMENT SYSTEM\n");
        printf("ENTER YOUR CHOICE.\n");
        scanf("%d",&ch);
        getchar(); // flushes newline before next fgets
        if(ch==1)
        {
            FILE *p;
            p = fopen("data.txt","ab+");
            if(p == NULL)
            printf("Error\n");
            else
            {
            input(p);
            fclose(p);
            }
        }
        else if(ch == 2)
        {
            FILE *p;
            p = fopen("data.txt","rb");
            FILE *q;
            q = fopen("newdata.txt","wb");
            if(p == NULL || q == NULL)
            printf("Error\n");
            else
            delete_record(p,q);
        }
        else if(ch == 3)
        {
            FILE *p = fopen("data.txt","rb+");
            if(p == NULL)
            printf("Error\n");
            else
            {
            check(p);
            fclose(p);
            }
        }
        else if(ch == 4)
        {
            printf("Exiting EMPLOYEE PAYROLL MANAGEMENT SYSTEM\n");
            break;
        }
        else
        printf("Invalid Choice. Please Retry!\n");

}
    }
    else
    printf("Invalid Credentials\n");
return 0;
}
