/*convert letters*/

#include<stdio.h>
#include<ctype.h>

void convert(FILE *fp1, FILE *fp2)
{
    int c;
    while((c=fgetc(fp1)) != EOF)
    {
        if (islower(c)) c = toupper(c);
        else if (isupper(c)) c = tolower(c);
        fputc(c,fp2);
    }
}

int main()
{
    FILE *fp1,*fp2;
    fp1 = fopen("lab1.txt","r");
    fp2 = fopen("lab1convert.txt","w");
    convert(fp1,fp2);
    fclose(fp1);
    fclose(fp2);
}