#include<stdio.h>
#include<stdlib.h>

//Time Complexity O(n^2)

int* SelectionSort(int* array,int total){
    for(int i=0; i<total-1; i++){
        int min = i;

        for(int j= i+1; j< total; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
    return array;
}

void main(){
    int i,total,number;

    printf("How many numbers? ");
    scanf("%d",&total);

    int array[total];
    int* sorted;

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        array[i] = number;
    }

    sorted = SelectionSort(array,total);

    for(int j=0; j<total; j++){
        printf("%d->",array[j]);
    }
}
