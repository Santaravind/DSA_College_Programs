//String Fibnocci words 

#include<stdio.h>
#include<string.h>
int main(){
     
   char str[50];
   char first[50]="A";
   char last[50]="B";
   int i=0,n=5;
   for(i=0; i<9; i++){
    strcpy(str,last);
    strcat(str,first);
    printf("%s\n",str);
    strcpy(first,last);
    strcpy(last,str);
   }
    return 0;

}