#include<stdio.h>
#include<string.h>

typedef struct Address{
    char name[25];
    char phone[12];
}info;

info SV[3];

void insertion_sort(info list[], int n) {
    info next;
    int i, j;
    for(i = 1; i < n; ++i) {
        next = list[i];
        for(j = i - 1; j >= 0 && strcmp(next.name, list[j].name) == -1; --j) {
            list[j+1] = list[j];
        }
        list[j+1] = next;
    }
}

void sort_ascending(info list[], int n) {
    FILE *fout = fopen("info1.txt", "w");
    insertion_sort(list, n);
    for(int i = 0; i < n; ++i) {
        fprintf(fout, "%s;%s\n", list[i].name, list[i].phone);
    }
}

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
    sort_ascending(SV,3);
    display(line);
    fclose(in);
}
