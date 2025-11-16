#include<stdio.h>
#include<string.h>
#include "employee.h"

void check(FILE *p)
{
    
    struct employee E;
    char c[50],pa[15];
    int l,L,x=0;
    fseek(p,0,2);
    if(ftell(p) == 0)
        {
        printf("No employee records found. Add an employee first\n");
        return;
        }
    printf("Enter username\n");
    fgets(c,50,stdin);
    l = strlen(c);
    if(c[l-1] == '\n')
    c[l-1] = '\0';
    printf("Enter password\n");
    scanf("%s",&pa);
    rewind(p);
    while(fread(&E,sizeof(E),1,p) == 1){
        if(strcmp(c,E.name) == 0 && strcmp(pa,E.password) == 0)
        {
            printf("Valid Credentials\n");
            printf("ID - %d\nName - %s\nHours Worked - %0.2f\nHourly Rate - %0.2f\nAllowances - %0.2f\nDeductions - %0.2f\nBonus - %0.2f\nMonthly Salary - %0.2f\n",E.id,E.name,E.hrsWorked,E.hrlyRate,E.allowances,E.deductions,E.bonus,E.monthSalary);
            x=1;
            break;
    }
}
if(x == 0)
printf("Invalid Credentials\n");
}