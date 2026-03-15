
#include<stdio.h>
#include<stdlib.h>
struct Stack {
    int info;
    struct Stack *next;
};
struct Stack *first=NULL,*last=NULL;
void push();
void pop();
void display();
int main(){
     int x;
     while(1){
     printf(" \nEnter 1 to push in stack \nEnter 2 pop form the stack\nEnter 3 For display the stack value\nEnter 4 for exit :-\nEnter value want to perform with stack:  ");
     scanf("%d",&x);
     
     switch(x){
        case 1:
        push();
        break;

        case 2:
        pop();
        break;

        case 3:
        display();
        break ;
        case 4:
        exit(0);
        break;

        default:
        printf("Enter valid  option\n");
    

     }
    }
    return 0;
}

void push(){
    struct Stack *p;
    p=(struct Stack *)malloc(sizeof(struct Stack));
    printf("Enter value that you want to add in stack \n");
    scanf("%d",&p->info);
    if(first==NULL){
        first=p;
        last=p;
    }else{
        last->next=p;
        last=p;
    }

    p->next=NULL;
}

void pop(){
    struct Stack *p=first;
    if(first==NULL){
        printf("\nStack is Empty !!\n");
        return;
    }
    if(first==last){
        printf("Popped Element = %d\t",p->info);
        free(p);
        last=NULL;
        first=NULL;
        return;
    }
   
   while(p->next!=last){
    
    p=p->next;
   }
   printf("Popped element =%d",last->info);
   free(last);
   last=p;
   p->next=NULL;
   
      
}

void display(){
    struct Stack *p;
    if(first==NULL){
        printf("\nStack is Empty!!\n");
        return ;
    }
    p=first;
     printf("Stack values:\t");
    while(p!=NULL){
        printf("%d\t",p->info);
        p=p->next;
    }

}