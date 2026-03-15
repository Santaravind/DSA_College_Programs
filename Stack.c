#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int stack[10];
int top=-1;
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
        continue;

     }
    }



    return 0;
}
void push(){
    int s;
    if(top>9){
        printf("Stack is Full !!");
        return ;
    }
    printf("Enter value that want to push in stack:\t");
    scanf("%d",&s);
    top++;
    stack[top]=s;
}

void pop(){
    if(top==-1){
        printf("Stack is Empty!!");
        return ;
    }
    int a=stack[top];
    top--;
    printf("Popped element =%d ",a);

}

void display(){
    if(top==-1){
        printf("\nStack is Empty\n");
        return ;
    }
    printf("Stack values \t:");
    while(top!=-1){
        printf("%d\t",stack[top--]);
    }
}