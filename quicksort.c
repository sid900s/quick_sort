
#include<stdio.h>


void display(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int*a,int low,int high){
    int pivot,temp,i,j;
    pivot=a[low];
    i=low+1;
    j=high;
    do{
        while(a[i]<=pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
   
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}

void quicksort(int*a,int low,int high){
    int partitionindex;
    if(low<high){
        partitionindex=partition(a,low,high);
        quicksort(a,low,partitionindex-1);
        quicksort(a,partitionindex+1,high);
    }
}

int main(){
     int a[] = {22, 15, 3, 9, 0, 10};
    int n = sizeof(a) / sizeof(int);
    display(a, n);
    quicksort(a, 0, n - 1);
    display(a, n);
    return 0;
}