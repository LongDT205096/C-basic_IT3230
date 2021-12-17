#ifndef _STACK_H
#define _STACK_H

typedef int stackS;
typedef struct stack* stack_t;

stack_t create(int size);

void push(stack_t root, int value); //thêm
void pop(stack_t root); //xóa

stackS top(stack_t root); //lấy giá trị đỉnh stack

int is_empty(stack_t root); //kiểm tra rỗng
int is_full(stack_t root); //kiểm tra đầy

#endif