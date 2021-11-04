#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct Q_node{
    int* data;
    int max_size;
    int front, rear;
};


typedef struct Q_node *queue;

queue create_queue(int max_size){
    queue p = (struct Q_node*)malloc(sizeof(struct Q_node));
    p->max_size = max_size;
    p->rear = -1;
    p->front = -1;
    p->data = (int*)malloc(max_size*sizeof(int));
    return p;
}

int is_empty(queue Q){
    return Q->rear == Q->front;    
}

int is_full(queue Q){
    return (Q->rear - Q->front+1) % Q->max_size == 0;
}

void enQueue(queue Q, int data){
    if(is_full(Q)){
        return;
    }
    Q->rear = (Q->rear+1) % Q->max_size;
    Q->data[Q->rear] = data;
    printf("%d enqueued to queue %d\n",data,Q->rear);
}

void deQueue(queue Q){
    if(is_empty(Q)){
        return;
    }
    Q->front = (Q->front+1)%Q->max_size;
    int a = Q->data[Q->front];
    Q->data[Q->front] = 0;
    printf("%d dequeued from queue %d\n",a,Q->front);
}

void displayQueue(queue Q){
    if (Q->front == -1){
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");

    if (Q->rear >= Q->front){
        for (int i = Q->front; i <= Q->rear; i++)
            printf("%d ",Q->data[i]);
    } else{
        for (int i = 0; i <= Q->rear; i++)
            printf("%d ", Q->data[i]);
    }
}

int main(){
    int count=0;
    queue Q = create_queue(10);
    enQueue(Q,10);
    enQueue(Q,20);
    deQueue(Q);  
    displayQueue(Q);  
}