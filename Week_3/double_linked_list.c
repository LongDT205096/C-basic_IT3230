#include<stdio.h>
#include<stdlib.h>

struct Dnode{
    int data;
    struct Dnode* prev;
    struct Dnode* next;
};

typedef struct Dnode *node;
struct Dnode *first;
struct Dnode *last;

node create(int data){
    node new = (struct Dnode*)malloc(sizeof(struct Dnode));
    new->data = data;
    new->prev = NULL;
    new->prev = NULL;
    return new;
}

void pop_front(){
    if(first == NULL){
        printf("Nothing to delete");
        return;
    }
    first = first->next;
    first->prev = NULL;
}

void pop_back(){
    if(first == NULL){
        printf("Nothing to delete");
        return;
    }
    last = last->prev;
    last->next = NULL;
}

void push_front(int data){
    node p = create(data);
    if(first == NULL && last == NULL){
        first = p;
        last = p;
        return;
    }
    first->prev = p;
    p->next = first;
    first = p;
}

void push_back(int data){
    node p = create(data);
    if(first == NULL && last == NULL){
        first = p;
        last = p;
        return;
    }
    last->next = p;
    p->prev = last;
    last = p;
}

void printList(node p){
    p = first;
    while (p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    int j;
    node p;
    printf("Nhap so phan tu can tao: ");
    scanf("%d",&j);
    for(int i=1; i<=j; i++){
        scanf("%d",&i);
        push_back(i);
    }
    printList(p);
    printf("Them phan tu '4' vao cuoi:\n");
    push_back(4);
    printList(p);
    printf("Xoa phan tu dau ra khoi list:\n");
    pop_front();
    printList(p);
}