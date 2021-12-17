#include<stdio.h>
#include<string.h>

typedef struct Address{
    char name[25];
    char phone[12];
}info;

info SV[3];

void getinfo(FILE *in,int n){
    char str[100];
    char name[30], phone[12];
    int j=0;
    while(fgets(str,100,in) != NULL){
        int i=0;
        
        str[strlen(str) - 1] = '\0';
        char *s = strtok(str,";");
        while (s != NULL){  
            if(i==0){
                strcpy(SV[j].name,s);
            } else if(i==1){
                strcpy(SV[j].phone,s);
                j++;
            }       
        i++;
        s = strtok(NULL,";");
        }
    }
}

void display(int n){
    for(int i = 0; i<n; i++){
        printf("%-25s%-12s\n",SV[i].name,SV[i].phone);
    }
}

int main(){
    FILE *in;
    in = fopen("info.txt","r");
    int line=3;
    getinfo(in,line);
    display(line);
    fclose(in);
}