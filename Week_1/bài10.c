/*Create "lab1.txt" and copy to "lab1w.txt*/

#include<stdio.h>

void create(FILE *fp1, FILE *fp2)
{
    char file1[] = "lab1.txt";
    char file2[] = "lab1w.txt";
    fp1 = fopen("lab1.txt","w");
    fprintf(fp1, "Hello world");
    fclose(fp1); 
}

void copy(char s[], FILE *fp1, FILE *fp2)
{
    fp1 = fopen("lab1.txt","r");
    fp2 = fopen("lab1w.txt","w");
    while(fgets(s,100,fp1) != NULL){
        fputs(s,fp2);
    }
    fclose(fp1);
    fclose(fp2);
}

int main()
{
    FILE *fp1,*fp2;
    create(fp1,fp2);
    char s[100];
    copy(s,fp1,fp2);
}