#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<stdio.h>

struct employee
{
    int id;
    char name[50];
    char password[15];
    float allowances;
    float deductions;
    float bonus;
    float hrsWorked;
    float hrlyRate;
    float monthSalary;
};

void input(FILE *p);
void check(FILE *p);
void delete_record(FILE *p, FILE *q);

#endif