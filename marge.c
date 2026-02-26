#include<stdio.h>

int a[10] ,b[10];

void margeSort(int , int );
void marge(int , int , int);

int  main(){
    int i; 

    for(i=0; i<=9; i++){
        printf("Enter the value of array =%d\t",i+1);
        scanf("%d",&a[i]);
    }

    margeSort(0,9);
    printf("your sorted array ");
    for(i=0; i<=9; i++){
        printf("%d\t",a[i]);
    }
   
}

void margeSort(int low , int high){
    int mid=(high+low)/2;
    if(low<high){
        margeSort(low, mid);
        margeSort(mid+1, high);

        marge(low, mid, high);
    }
}

void marge(int low, int mid,int high){

    int i=low;
    int j=mid+1;
    int k=low;
    int l;
    while((i<=mid)&&(j<=high)){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
        }else
        {
            b[k]=a[j];
            j++;
         }
         k++;
    }
    if(i>mid){
        for(l=j; l<=high; l++){
            b[k]=a[l];
            k++;
        }
    }else
    {
        for(l=i; l<=mid; l++){
            b[k]=a[l];
            k++;
        }
    }

    for(l=low; l<=high; l++)
    {
        a[l]=b[l];
    }
}