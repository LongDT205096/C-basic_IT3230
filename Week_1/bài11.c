/*length of lines*/

#include<stdio.h>
#include<string.h>

void count(FILE *fp1, FILE *fp2)
{
    char c[100];
    int a;
    while ((fgets(c,100,fp1)) != NULL)
    {
        a = strlen(c);
        fprintf(fp2,"%d %s",a,c);
    }
}

int main()
{
    FILE *fp1,*fp2;
    fp1 = fopen("lab1.txt","r");
    fp2 = fopen("lab1length.txt","w");
    count(fp1,fp2);
    fclose(fp1);
    fclose(fp2);
}