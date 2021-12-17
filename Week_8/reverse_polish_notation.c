#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node *left;
    struct node *right;
    struct node *next;
};

typedef struct node* Bnode;
struct node *root = NULL;

Bnode create(char data){
    Bnode new = (struct node*)malloc(sizeof(struct node));
    new -> data = data;
    new -> left = NULL;
    new -> right = NULL;
    new -> next = NULL;
    return new;
}

void traversal(Bnode root){
    if(root == NULL){
        return;
    } else{
        traversal(root->left);
        printf("%c",root->data);
        traversal(root->right);
    }
}

void push(Bnode p){
    if(root == NULL){
        root = p;
    } else{
        p->next = root;
        root = p;
    }
}

Bnode pop(){
    Bnode p = root;
    root = root -> next;
    return p;
}

int main(){
    char s[] = {'A','B','C','*','+','D','/'};
    int n = sizeof(s) / sizeof(s[0]) ;
    Bnode x, y, z;

    for (int i = 0; i < n; i++){
        if (s[i] == '+' || s[i] == '-' || s[i] == '*'|| s[i] == '/' || s[i] == '^'){
            z = create(s[i]);
            x = pop(z);
            y = pop(z);
            z->left = y;
            z->right = x;
            push(z);
        } else{
            z = create(s[i]);
            push(z);
        }
    }
    printf("The Inorder Traversal of Expression Tree: ");
    traversal(z);
    return 0;
}