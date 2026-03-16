#include<stdio.h>
#include<stdlib.h>
struct queue {
    int info;
    struct queue *next;
};
void queue();
void dequeue();
void display();
struct queue *first=NULL,*last=NULL;
int main(){
    int x;
    while(1){
    printf(" \nEnter 1 to push in queue \nEnter 2 pop form the queue\nEnter 3 For display the queue value\nEnter 4 for exit :-\nEnter value want to perform with queue:  ");
    scanf("%d",&x);
    
    switch(x){
       case 1:
       queue();
       break;
       case 2:
       dequeue();
       break;

       case 3:
       display();
       break ;
       case 4:
       exit(0);
       break;

       default:
       printf("Enter valid  option\n");
       continue;

    }
   }  
    return 0;
}
void queue(){
    struct queue *p;
    p=(struct queue *)malloc(sizeof(struct queue));
    printf("Enter value that want to insert\t:");
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


    void dequeue(){
        struct queue *p;
    
        if(first == NULL){
            printf("\nQueue is Empty !!");
            return;
        }
        p = first;
        printf("Delete element : %d\t", p->info);
    
        first = first->next;
    
        free(p);
    }

void display(){
    struct queue *p;
    p=first;
     
    if(first==NULL){
        printf("\nQueue is Empty !!");
        return;
    }
    printf("\nQueue elements :\t");
    while(p!=NULL){
        printf("%d\t", p->info);
        p=p->next;
    }




}