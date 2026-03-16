#include<stdio.h>
#include<stdlib.h>
int Queue[10];
int front=-1;
int rear=-1;
void queue();
void dequeue();
void display();
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
    if(rear==9){
       printf("Queue is Full !!");
       return  ;
    }
    int x;
    printf("\nEnter the value that want to insert into Queue \t");
    scanf("%d",&x);
    if(front==-1){
        front++;
        rear++;
    }else{
        rear++;
    }
    Queue[rear]=x;
}

void dequeue(){
    int x;
        if(front==-1){
            printf("\nQueue is empty:");
            return ;
        }
        x=Queue[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }else{
        front++;
    }

    printf("\nDe_queue element:\t%d\t",x);

}

void display(){
    if(front==-1){
        printf("\nQueue is Empty!!\t");
        return ;
    }
    int x=front,i;
    printf("\nQueue elements :");
    for(i=x; i<=rear; i++){
        printf("%d\t",Queue[i]);
    }
}