#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "stack.h"

int main() {
    FILE *in;
    in = fopen("infix.txt","r");
    char a;
    stack_t root = create(100);
    stack_t result = create(100);
    stack_t math = create(100);
    int num1, num2;

    while((a=fgetc(in)) != EOF){
        if(a == ')'){
            while(!is_empty(root)){
                printf("%c ",(char)top(root));
                pop(root);
            }
        }
        if(a == '+' || a == '*' || a == '-' || a == '/'){
            push(root,a);
            push(math,a);
        }
        if(a >= '0' && a <= '9'){
            printf("%c ",a); 
            push(result,a-48);
        }     
    }

    int sum;

    while(!is_empty(math)){
        char b = (char)top(math);
        pop(math);
        int a2 = (int)top(result);
        pop(result);
        sum = (int)top(result);
        pop(result);
        if(b == '+') sum += a2;
        if(b == '-') sum -= a2;
        if(b == '*') sum *= a2;
        if(b == '/') sum /= a2;
        push(result,sum);
    }
    printf("\n%d",sum);
//đẩy dấu và số vào 2 stack riêng, lấy từng phần tử ra để thực hiện phép tính
    
    fclose(in);
}