#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *next;
};
struct node *first=NULL , *last=NULL;

void create();
void taverse();
void insertFirst();
void insertLast();
void insertinbetween();
void deletfirst();

void deletLast();
void deleteingiven();

int main(){
    int x;
     
    // printf("what is you want to do with linked list\n");
    // printf("Enter 1 if want to create node\n");
    // printf("Enter 2 if want to  insert element in first position \n");
    // printf("Enter 3 if want to  insert element in last position\n");
    // printf("Enter 4 if want to  insert element in between position\n");
    // printf("Enter 5 if wnat to delete first node \n");
    // printf("Enter 6 if want to delete last node\n");
    // printf("Enter 7 if want to delete any node  \n");
    
    
    char ch;
    do{
        printf("what is you want to do with linked list\n");
       printf("Enter 1 if want to create node\n");
       printf("Enter 2 if want to  insert element in first position \n");
    printf("Enter 3 if want to  insert element in last position\n");
    printf("Enter 4 if want to  insert element in between position\n");
    printf("Enter 5 if wnat to delete first node \n");
    printf("Enter 6 if want to delete last node\n");
    printf("Enter 7 if want to delete any node  \n");
    printf("Enter 8 if want to print notes  \n");

        printf("\nEnter you choice\t");
        scanf("%d",&x);

        switch(x){
       
        case 1:
        create();
        taverse();
        break;
        case 2:
        insertFirst();
        taverse();
        break;
        case 3:
        insertLast();
        taverse();        
        break;
        case 4:
        insertinbetween();
        taverse();
        break;
        case 5:
        deletfirst();
        taverse();
        break;
        case 6:
        deletLast();
        taverse();
        break;
        case 7:
        deleteingiven();
        taverse();
        break;
        case 8:
        taverse();
        break;
         
        default :
        printf("Your choice is wrong ");
    }

    printf("Do you want to  continue to press yes Y or y other wish N");
    scanf(" %c",&ch);

}while(ch=='y'||ch=='Y');
   


    return 0;
}

void create (){

  struct node *p;
   int x;
   while(1){
    p=(struct node *)malloc(sizeof(struct node));
    printf("Eneter value\t");
    scanf("%d", &p->info);
    if(first==NULL){
        first=p;
        last=p;
    }
    else{
        last->next=p;
        last=p;
    }
    printf("press 1 if want new node\t");
    scanf("%d",&x);
    if(x!=1){
        break;
    }

   }
   
   last->next=NULL;

}

void taverse(){
    struct node *p;
    p=first;

    while(p!=NULL){
        printf("%d\t",p->info);
        p=p->next;
    }
    printf("\n");
}

void insertFirst(){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Eneter value that want to insert in first\t");
    scanf("%d", &p->info);
    if(first==NULL){
        first=p;
        last=p;

    }else{
        p->next=first;
        first=p;
    }
    p->next=NULL;
}

void insertLast(){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    printf("\nEneter value that want to insert in last ");
    scanf("%d", &p->info);
    if(first==NULL){
        first=p;
        last=p;
    }else{
        last->next=p;
        last=p;
    }
    p->next=NULL;


}

void insertinbetween(){
    struct node *p ,*q;
    int x;
    printf("Enter the value that after you want to insert");
    scanf("%d",&x);
    if(first==NULL){
        printf("\nlist not exist");
        return ;
    }
    p=first;
    while(p!=NULL){
        if(p->info==x){
            break;
        }
        p=p->next;
    }
    if(p==NULL){
        printf("\nnode not found ");
        return  ;
    }
    q=(struct node *)malloc(sizeof(struct node));
    printf("\tEneter value that want to insert  ");
    scanf("%d", &q->info);
    q->next=p->next;
    p->next=q;
    if(q->next==NULL){
        last=q;
    }


}

void deletfirst(){
    struct node *p;
    p=first;
    if(p==NULL){
        return;
    }
    if(first==last){
        first=NULL;
        last=NULL;
    }else{
        first=first->next;
    }
    free(p);
}

void deletLast() {
    struct node *p, *q;

    if (first == NULL) {
        return;
    }

   
    if (first == last) {
        free(first);
        first = NULL;
        last = NULL;
        return;
    }

    q = first;

    
    while (q->next != last) {
        q = q->next;
    }

    free(last);

    q->next = NULL;
    last = q;
}

void  deleteingiven(){
     int x;
     struct node *p,*q;
     printf("\nEnter info that after node you want to  delete\t");
     scanf("%d",&x);
      p=first;
      q=last;
      while((p!=NULL)&&(p->info!=x)){
        q=p;
        p=p->next;
      }
      if(q==NULL){
        printf("\nlist not exit");
        return;
      }
      if(p==NULL){
        printf("\nnode not exist");
        return;
      }
      if(first==last){
        first=NULL;
        last=NULL;
        free(p);
        return;
      }

      if(p==first){
        deletfirst();
        return;
      }
      if(p==last){
        deletLast();
        return;
      }
      q->next=p->next;
      free(p);
}