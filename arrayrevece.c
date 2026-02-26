
//Array Reverce 
#include<stdio.h>
int main(){
     int arr[]={0,2,3,4,5,6,7};
     int n=sizeof(arr)/sizeof(arr[0]);
     int i=0,j=0,k=0;
     int temp;
     for(i=0; i<n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
     }

     for(k=0; k<n; k++){
        printf("%d ",arr[k]);
     }
    return 0;
}