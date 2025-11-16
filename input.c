#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "employee.h"


void input(FILE *p)
{
    int i,n,l,s;
    printf("Enter Number of employees to add\n");
    scanf("%d",&n);
    struct employee *E = (struct employee *)calloc(n,sizeof(struct employee));
    if(E == NULL)
   {
     printf("Memory Not Allocated\n");
     return;
   }
    for(i=0;i<n;i++){
    printf("Employee %d\n",(i+1));
    printf("ID -\n");
    scanf("%d",&E[i].id);
    getchar();
    printf("Name of employee -\n");
    fgets(E[i].name,50,stdin);
    l = strlen(E[i].name);
    if(E[i].name[l-1] == '\n')
    E[i].name[l-1] = '\0';
    printf("Password -\n");
    scanf(" %s",E[i].password);
    printf("Hours Worked-\n");
    scanf("%f",&E[i].hrsWorked);
    printf("Hourly Rate-\n");
    scanf("%f",&E[i].hrlyRate);
    printf("Any Allowances for this specific Employee?\nPress 1 if yes otherwise Press 0\n");
    scanf("%d",&s);
    if(s == 1)
    {
    printf("Enter Allowances -\n");
    scanf("%f",&E[i].allowances);
    }
    else
    E[i].allowances =0.0;
    printf("Any Deductions for this specific Employee?\nPress 1 if yes otherwise Press 0\n");
    scanf("%d",&s);
    if(s == 1)
    {
    printf("Enter Deductions -\n");
    scanf("%f",&E[i].deductions);
    }
    else
    E[i].deductions = 0.0;
    printf("Any Bonus for this specific Employee?\nPress 1 if yes otherwise Press 0\n");
    scanf("%d",&s);
    if(s == 1)
    {
    printf("Bonus -\n");
    scanf("%f",&E[i].bonus);
    }
    else
    E[i].bonus = 0.0;
    E[i].monthSalary = (E[i].hrsWorked*E[i].hrlyRate)+E[i].allowances+E[i].bonus-E[i].deductions;
    fwrite(&E[i],sizeof(struct employee),1,p);
    //Confirmation line
    printf("Employee data for Employee %d is stored\n",(i+1));
    }
    free(E);
}