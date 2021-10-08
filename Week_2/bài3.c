/*phone numbers*/

#include<stdio.h>

typedef struct {
    char name[20];
    char num[11];
    char email[50];
}address;

int main()
{
    FILE *fp;
    address add[100];
    int s,i;
    printf("Nhap so luong so lien lac: ");
        scanf("%d",&s);
    for(i=0; i<s; i++){
        printf("Ten: "); scanf("%s",add[i].name);
        printf("So dt: "); scanf("%s",add[i].num);
        printf("Email: "); scanf("%s",add[i].email);
    }

    fp = fopen("Danh_ba.txt","wb");
    fwrite(add,sizeof(address),s,fp);
    fclose(fp);

    fp = fopen("Danh_ba.txt","rb");
    int read = fread(add,sizeof(address),s,fp);
    for(i=0; i<s; i++){
        printf("Ten: %s ",add[i].name);
        printf("So dt: %s ",add[i].num);
        printf("Email: %s ",add[i].email);
        printf("\n");
    }
    fclose(fp);
}