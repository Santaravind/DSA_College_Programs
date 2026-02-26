
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main(){
  
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    circle(500,500,100);




    getch();
    closegraph();
}
