#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "stack.h"

int main() {
    FILE *in;
    in = fopen("kiphapbalan.txt","r");
    char a;
    stack_t root = create(100);
    while((a=fgetc(in)) != EOF){
        if(a == ')'){
            while(!is_empty(root)){
                printf("%c ",(char)top(root));
                pop(root);
            }
        }
        if(a == '+' || a == '*') push(root,a);
        if(a >= '0' && a <= '9') printf("%c ",a);
    }
    fclose(in);
}  