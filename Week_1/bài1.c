/*reverse*/

#include<stdio.h>
int main()
{
    int i, n[10];
    printf("Nhap day so: ");
    for ( i = 0; i < 10; i++)
        {
            scanf("%d",&n[i]);
        }
    printf("Dao nguoc day so: ");
    for ( i = 9; 0 <= i; i++)
    {
        printf("%d",n[i]);
    }  
}