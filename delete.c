#include<stdio.h>
#include<string.h>
#include "employee.h"

void delete_record( FILE *p, FILE *q)
{
        struct employee E;
        int x=0,l;
        char c[50];
        fseek(p,0,2);
        if(ftell(p) == 0)
        {
        printf("No employee records found. Add an employee first\n");
        return;
        }
        rewind(p);
        printf("Enter the name to be deleted\n");
        fgets(c,50,stdin);
        l = strlen(c);
        if(c[l-1] == '\n')
        c[l-1] = '\0';
        while(fread(&E,sizeof(E),1,p) == 1){
            if(strcmp(c,E.name) != 0)
            fwrite(&E,sizeof(E),1,q);
            else
            x=1;
        }
        if(x==0)
        printf("Name not found\n");
        else
        printf("Record deleted\n");
        fclose(p);
        fclose(q);
        remove("data.txt");
        rename("newdata.txt","data.txt");

    }