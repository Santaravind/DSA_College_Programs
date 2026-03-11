#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *pre, *next;
};

struct node *first=NULL,*last=NULL;
void create();
void insertinbetween();
void taverse_backword();
void taverse_forword();
void insert_last();
void insert_First();
void deleteFirst();
void deleteLast();
void delete_To_Give_Node();

int main(){

    int x;
   
    char ch;
    do{
      
        printf("what is you want to do with linked list\n");
    printf("Enter 1 if want to create node\n");
    printf("Enter 2 if want to  insert element in first position \n");
    printf("Enter 3 if want to  insert element in last position\n");
    printf("Enter 4 if want to  insert element in between position\n");
    printf("Enter 5 if want to  delete element in first position \n");
    printf("Enter 6 if want to  delete element in last position\n");
    printf("Enter 7 if want to  delete element in given possion\n");
    printf("Enter 8 to print forword list \n");
    printf("Enter 9 to print backword  list \n");
    printf("Enter your choice: ");
    scanf("%d",&x);

    switch(x){
        case 1:
        create();
        break;
       case 2:
        insert_First();
        break;
        case 3:
        insert_last();
        break;
        case 4:
        insertinbetween();
        break;
        case 5:
        deleteFirst();
        break;
        case 6:
        deleteLast();
        break;
        case 7:
        delete_To_Give_Node();
        break;
        case 8:
        taverse_forword();
        break ;
        case 9:
        taverse_backword();
       
        break ;


        default :
        printf("You are Enter wrong choice:---");


    }
    printf("\nDo you want to  continue to press yes Y or y other wish N: ");
    scanf(" %c",&ch);

}while(ch=='y'||ch=='Y');
      
    // create();
    // taverse_backword();
    // taverse_forword();

    return 0;
}

void create(){
    struct node *p;
     int x;
    while(1){
        p=(struct node *)malloc(sizeof(struct node));
        printf("Enter the info :\t");
        scanf("%d",&p->info);

        if(first == NULL){
            first=p;
            last=p;
            p->pre=NULL;
        }else{
            last->next=p;
            p->pre=last;
            last=p;
        }

        printf("Enter 1 for new node");
        scanf("%d",&x);
        if(x!=1){
            break;
        }
        last->next=NULL;
    }
}

void taverse_backword(){
    struct node *p=last;
  
    if(last==NULL){
        printf("Node list not exixt ");
    }
     printf("List items forword \t");
    while(p!=NULL){
        printf("%d->",p->info);
        p=p->pre;
    }


}

void taverse_forword(){
    struct node *p=first;
  
    if(last==NULL){
        printf("Node list not exixt ");
    }
     printf("List items forword \t");
    while(p!=NULL){
        printf("%d->",p->info);
        p=p->next;
    }
}

void insert_First(){
    struct node *p; 
             p=(struct node *)malloc(sizeof(struct node));
        printf("Enter the info :\t");
        scanf("%d",&p->info);
    if(first==NULL){
       first=p;
       last=p;
       p->next=NULL;
    }else{
 
         first->pre=p;
         p->next=first;
         first=p;
         
    }
    p->pre=NULL;
   

}

void insert_last(){
    struct node *p; 
  p=(struct node *)malloc(sizeof(struct node));
        printf("Enter the info :\t");
        scanf("%d",&p->info);
    if(first==NULL){
       first=p;
       last=p;
       p->next=NULL;
    }else{
 
         last->next=p;
         p->pre=last;
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
    q->pre=p;
    p->next=q;
    if(q->next==NULL){
        last=q;
    }else{
        q->next->pre=q;
    }


}

void deleteFirst(){
    struct node *p;

    p=first;
    if(first==NULL){
         printf("Node not exits\t");
         return;
    }
    if(first==last){
        first=NULL;
        last=NULL;
        
    }else{
      first= first->next;
        first->pre=NULL;
    }
    printf("Deleted node is:\t %d",p->info);
    free(p);
}

void deleteLast(){
    struct node *p;
    p=last;
    if(first==NULL){
        printf("list not exist:\t");
        return ;
            }
            
            if(first==last){
                first=NULL;
                last=NULL;
                printf("Deleted node is \t: %d",p->info);
                free(p);
            }else{
            last=last->pre;
            last->next=NULL;
            printf("Deleted node is \t: %d",p->info);
            free(p);
            }

            
}

void delete_To_Give_Node(){
    struct node *p,*prive;

    p=first;
    if(first=NULL){
    printf("list not exist\t");
    return ;
    }
    int x;
    printf("Enter node value that you want to delete\t");
    scanf("%d",&x);
    while((p!=NULL)&&(p->info!=x)){
        prive=p;
        p=p->next;

    }
    if(p==NULL){
        printf("node not exist:\t");
        return  ;
    }

    if(p==first){
        first=first->next;
        first->pre=NULL;
        printf("Deleted node :\t%d",p->info);
        // free(p);
    }

    if(p==last){
        last=last->pre;
        last->next=NULL;
        printf("Deleted node :\t%d",p->info);
        // free(p);
    }else{
        prive->next=p->next;
      
        p->next->pre =prive;
        prive->next=p;
       
        // p->pre=NULL;
        printf("Deleted node :\t%d",p->info);
        }

        free(p);

}


