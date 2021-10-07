/*replace with pointers*/

#include<stdio.h>

void thaythe(char *str, char a, char b)
{
    if(str == NULL)
        return;
    while(*str != '\0')
        {
            if(*str == a)
                *str = b;
            ++str;
        }
}
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
    thaythe(s,a,b);
    printf("%s",s);
}