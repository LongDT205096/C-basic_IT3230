/*strcat*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *string(char *s1,char *s2)
{
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    char *s3;
    s3 = (char*)malloc((n1 + n2 + 1)*sizeof(char));
    s3 = strcat(s1,s2);
    return s3;
}

int main()
{
    char s1[100],s2[100],*s3;
    printf("Nhap chuoi 1: ");
    scanf("%s",&s1);
    fflush(stdin);
    printf("Nhap chuoi 2: ");
    scanf("%s",&s2);
    s3 = string(s1,s2);
    if(s3 == NULL){
        printf("Error!");
    }
    else{
        printf("%s",s3);
    }
    free(s3);
}