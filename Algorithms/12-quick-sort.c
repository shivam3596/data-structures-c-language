#include<stdio.h>
#include<stdlib.h>

//Time complexity in best and avg case : O(n log n)
// in worst case: O(n^2) , we can improve this by using randomised quick sort

int Partition(int* array, int start, int end){
    int pivot = array[end];
    int partitionIndex = start;

    for(int i=start; i<end; i++){
        if(array[i] <= pivot){
            int temp1 = array[i];
            array[i] = array[partitionIndex];
            array[partitionIndex] = temp1;
            partitionIndex++;
        }
    }
    int temp2 = array[end];
    array[end] = array[partitionIndex];
    array[partitionIndex] = temp2;
    return partitionIndex;
}

void QuickSort(int* array, int start, int end){
    //base condition
    if(start < end){
        int partitionIndex = Partition(array,start,end);
        QuickSort(array,start,partitionIndex-1);
        QuickSort(array,partitionIndex+1,end);
    }
}

void main(){
    int i,total,number;

    printf("how many numbers?");
    scanf("%d",&total);

    int array[total];

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        array[i] = number;
    }

    QuickSort(array,0,total-1);

    for(int j=0; j<total; j++){
        printf("%d->",array[j]);
    }
}
