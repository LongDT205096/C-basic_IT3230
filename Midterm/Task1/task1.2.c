#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct students{
    char name[25];
    char phone[12];

    struct students *next;
};


typedef struct students* student_t;


student_t init(){
    student_t root;
    root = NULL;
    return root;
}

student_t create_student_t(char name[], char phone[]) {
    student_t new;
    new = (student_t)malloc(sizeof(struct students));
    new->next = NULL;
    strcpy(new->name,name);
    strcpy(new->phone,phone);
    return new;
}

student_t delHead(student_t root){
    if(root = NULL){
        printf("Error");
    } else{
        root = root->next;
    }
    return root;
}

student_t delTail(student_t root){
    if(root == NULL || root->next == NULL){
        return delHead(root);
    } else{
        student_t p = root;
        while(p->next->next != NULL){
            p = p->next;
        }
        p->next = p->next->next;
        return root;
    }
}

student_t delAt(student_t root,char *name){
    printf("Nhap id can xoa");
    scanf("%s",name);

    student_t p = root,prev;

    while (p!=NULL && strcmp(p->name,name)!=0){
        prev = p;
        p = p->next;
    }
    if(p!=NULL){
        prev->next = p->next;
        free(p);
    }
    return root;  
}

//thực hiện thêm dữ liệu theo thứ tự bảng chữ cái
student_t add_student(student_t root, student_t to_add) {
    student_t cur_student, prev_student = NULL;
    if(root == NULL) {
        return to_add;
    }

    if(strcmp(to_add->name,root->name)<0) {
        to_add->next = root;
        return to_add;
    }

    cur_student = root;
    while(cur_student != NULL && strcmp(to_add->name,cur_student->name)>=0) {
        prev_student = cur_student;
        cur_student = cur_student->next;
    }

    prev_student->next = to_add;
    to_add->next = cur_student;
    return root;
}

student_t getinfo(FILE *in){
    student_t add, root = init();
    char str[100];
    char name[30], phone[12];
    while(fgets(str,100,in) != NULL){
        int i=0;
        str[strlen(str) - 1] = '\0';
        char *s = strtok(str,";");
        while (s != NULL){  
            if(i==0){
                strcpy(name,s);
                printf("%s ",name);
            } else if(i==1){
                strcpy(phone,s);
                printf("%s\n",phone);
            }       
        i++;
        s = strtok(NULL,";");
        } 
        add = create_student_t(name,phone);   
        root = add_student(root,add); 
    }
    return root;
}

student_t find(student_t root, char *phone){ 
    student_t p = root;
    while (p != NULL && strcmp(p->phone,phone)!= 0){
        p = p->next;
    }
    return p;
}

void traversing(student_t root){
    printf("|Name                         |Phone     |\n");
    for(student_t st = root; st != NULL; st = st->next){
        printf("|%-29s|%-10s|\n", st->name, st->phone);
    }
}

int main(){
    FILE *in;
    in = fopen("info.txt","r");
    student_t root = getinfo(in);
    traversing(root);
    
    char phonef[30];
    printf("Nhap so dt can tim: ");
    scanf("%s",phonef);
    student_t found = find(root,phonef);

    if(found != NULL){
        printf("%s %s",found->name,found->phone);
    } else{
        printf("Not found");
    }

    fclose(in);
}
