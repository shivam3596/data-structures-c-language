#include<stdio.h>
#include<stdlib.h>

//Time Complexity O(n^2) in worst case
//in best case O(n)

int* InsertionSort(int* array, int total){
    for(int i=1; i<total; i++){
        int hole = i;
        int value = array[i];

        while(hole > 0 && array[hole-1] > value){
            array[hole] = array[hole-1];
            hole--;
        }
        array[hole] = value;
    }
    return array;
}

void main(){
    int i,j,total,number;

    printf("how many numbers?");
    scanf("%d",&total);

    int array[total];
    int* sorted;

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        array[i] = number;
    }

    sorted = InsertionSort(array,total);

    for(j=0; j<total; j++){
        printf("%d->",sorted[j]);
    }
}
