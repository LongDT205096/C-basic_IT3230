#include<stdio.h>

int search(int key, int r[], int n){
    int i,j;
    int temp;
    for (i=0; i<n; i++){
        if(r[i] == key){
            if(i>0){
                temp = r[i];
                for (j=i; j>0; j--){
                    r[j] = r[j-1];
                }
                r[0] = temp;
                return i; 
                break;
            }  
        return 0; 
        } 
    } return -1;
}

int main(){
    int a[5];
    int i;

    for (i=0; i<5; i++){
        scanf("%d",&a[i]);
    }
    
    int key = 4;
    int b = search(key,a,5);
    printf("%d",b);    
}