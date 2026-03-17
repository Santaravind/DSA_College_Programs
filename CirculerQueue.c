#include<stdio.h>
#include<stdlib.h>
#define max 10
int Queue[max];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void display();
int main(){
     int x;
     while(1){
     printf(" \nEnter 1 to push in queue \nEnter 2 pop form the queue\nEnter 3 For display the queue value\nEnter 4 for exit :-\nEnter value want to perform with queue:  ");
     scanf("%d",&x);
     
     switch(x){
        case 1:
        enqueue();
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
}
void enqueue(){
    int x;
    if((front==0)&&(rear==max-1)||(rear==front-1)){
        printf("Queue is full");
        return;
    }

    printf("\nEnter value that want insert in queue\t");
    scanf("%d",&x);
    if(front==-1){
        front=0;
        rear=0;
    }else{
        rear=(rear+1)%10;
    }
    Queue[rear]=x;
}

void dequeue(){
    int x;
     if(front==-1){
        printf("Queue is empty!!");
        return;
     }

     x=Queue[front];
     if(front==rear){
        front=-1;
        rear=-1;
     }else{
        front=(front+1)%10;
     }

     printf("Dequeue element is=%d",x);
}
void display(){
    int x=front;

    if(front==-1){
        printf("Queue is Empty!!");
        return ;

    }
    printf("Circuler queue element:\t");
    while(x!=rear){
        printf("%d ",Queue[x]);
        x=(x+1)%10;
    }
    printf("%d",Queue[x]);

}