/*compare*/

#include<stdio.h>
#include<string.h>
int main()
{
    int a[100],b[100];
    int n,m;
    printf("Nhap kich co mang : ");
    scanf("%d",&n);
    for(int i=0;i<n; i++)
        scanf("Nhap mang a:",a[i]);
    for(int i=0;i<n; i++)
        scanf("Nhap mang b:",b[i]);
    for(int i=0;i<n; i++)
        {
            if(a[i] != b[i])
                return 0;
        }
    return 1;
}