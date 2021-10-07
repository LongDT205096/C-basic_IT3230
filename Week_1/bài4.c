/*replace characters*/

#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    char a,b;
    printf("Nhap ki tu xoa: ");
        scanf("%c",&a);
    fflush(stdin);
    printf("Nhap ki tu thay the: ");
        scanf("%c",&b);
    printf("Nhap chuoi: ");
        scanf("%s",s);
    for(int i=0; i< strlen(s); i++)
        {
            if(s[i] == a)
                s[i] = b;
            printf("%c",s[i]);
        }
}