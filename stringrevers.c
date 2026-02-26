//Revece an String 

#include<stdio.h>
int main(){
    char n[25]="Aravind sant singh";
    int i=0,j=0;
    while(n[i]!='\0'){
        
        i++;
    }
    for(j=i-1;j>=0; j--){
        printf("%c",n[j]);
    }
    // printf("%d",i);
}