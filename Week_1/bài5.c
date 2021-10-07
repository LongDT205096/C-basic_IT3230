/*split*/

#include<stdio.h>
void tachso(double num, int *a, double *b)
{
        *a = (int)num;
        *b = num - (*a);
}

int main()
{
    double num,b;
    int a;
    printf("Nhap so: ");
    scanf("%lf",&num);
    tachso(num,&a,&b);
    printf("Phan nguyen: %d\n",a);
    printf("Phan thap phan: %f\n",b);
}