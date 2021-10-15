#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    int *p;
    int i,n,value;
    int sum=0;
    printf("Nhap so luong so: ");
        scanf("%d",&n);
    p = (int *)malloc(n*sizeof(int));
    printf("Nhap day so: ");
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
        sum += p[i];
    }
    fp = fopen("out.txt","w");
    for(i=n-1;0<=i;i--){
        fprintf(fp,"%d ",p[i]);
        
    } fprintf(fp,"%d",sum);
    fclose(fp);
    free(p);

}