/*displays the number of times*/

#include<stdio.h>
#include<string.h>
#define ALPHABET 26
int main()
{
    char s[100];
    printf("Nhap chuoi: ");
    gets(s);
    fflush(stdin);
    int c[ALPHABET]={0};
    for (int i = 0;i<strlen(s); i++ )
        {
            if(s[i] >= 'a' && s[i] <= 'z')
                c[s[i] - 'a']++;
        }
    for(int j=0; j < ALPHABET; j++)
        if(c[j] > 0)
            printf("Ki tu %c xuat hien %d lan\n",j + 'a',c[j]);
}