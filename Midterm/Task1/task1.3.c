#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

struct Q_node{
    char** phone;
    char** name; 
    int max_size;
    int front, rear;
};

typedef struct Q_node *queue;

queue create_queue(int max_size){
    queue p = (struct Q_node*)malloc(sizeof(struct Q_node));
    p->max_size = max_size;
    p->rear = 0;
    p->front = 0;
    p->phone = (char**)malloc(max_size*sizeof(char));
    p->name = (char**)malloc(max_size*sizeof(char));
    return p;
}

int is_empty(queue Q){
    return Q->rear == Q->front;    
}

int is_full(queue Q){
    return (Q->rear - Q->front+1) % Q->max_size == 0;
}

void enQueue(queue Q, char* name, char* phone){
    if(is_full(Q)){
        printf("Queue full\n");
    } else{
        Q->name[Q->rear] = (char*)malloc((sizeof name + 1)*sizeof(char));
        Q->phone[Q->rear] = (char*)malloc((sizeof phone + 1)*sizeof(char));
        strcpy(Q->name[Q->rear],name);
        strcpy(Q->phone[Q->rear],phone);
        printf("%s %s enqueued to queue %d\n",Q->name[Q->rear],Q->phone[Q->rear],Q->rear);
        Q->rear = (Q->rear+1) % Q->max_size;
    }
}

void deQueue(queue Q){
    if(is_empty(Q)){
        printf("Queue empty\n");
        return;
    } else{
        Q->front = (Q->front+1) % Q->max_size;
        printf("%d\n",Q->front);
    }
}

queue getinfo(FILE *in,queue Q){
    Q = create_queue(4);
    char str[100];
    char name[30], phone[10];
    while(fgets(str,100,in) != NULL){
        int i=0;
        str[strlen(str) - 1] = '\0';
        char *s = strtok(str,";");
        while (s != NULL){
            if(i==0){
                strcpy(name,s);
            } else if(i==1){
                strcpy(phone,s);
            }       
        i++;
        s = strtok(NULL,";");
        } 
        enQueue(Q,name,phone); 
    }
    return Q;
}


void displayQueue(queue Q){
    if (Q->rear == Q->front){
        printf("Queue is Empty\n");
        return;
    }

    printf("Elements in Circular Queue are:\n");

    if (Q->rear > Q->front){
        for (int i = Q->front; i < Q->rear; i++)
            printf("%-25s%-12s\n",Q->name[i],Q->phone[i]);
    } 
    else if(Q->rear < Q->front){
        for (int i = Q->front; i < Q->max_size; i++){
            printf("%s%-12s\n",Q->name[i],Q->phone[i]);
        }

        for(int i = 0; i < Q->rear; i++){
            printf("%-25s%-12s\n",Q->name[i],Q->phone[i]);
        }
    }
    printf("\n\n");
}


int main(){
    FILE *in;
    in = fopen("info.txt","r");
    queue Q;
    queue p = getinfo(in,Q);
    displayQueue(p);
    fclose(in);
}