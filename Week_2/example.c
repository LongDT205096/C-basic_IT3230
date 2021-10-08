/*reverse array*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,n,*k;

    printf("Nhap so luong so: ");
        scanf("%d",&n);
    
    k = (int*)malloc(n*sizeof(int));
    if(k == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Nhap mang: ");
    for(i=0; i<n; i++)
        {
            scanf("%d",&k[i]);
        }

    printf("Day so dao nguoc: ");
    for(i=n-1; i>=0; --i)
        {
            printf("%d ",k[i]);
        }
    free(k);
}