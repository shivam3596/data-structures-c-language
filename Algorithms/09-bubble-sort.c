#include<stdio.h>
#include<stdlib.h>

//Time Complexity (n^2)

int* BubbleSort(int* array,int total){
    int i,j;
    for(i=0; i<total-1; i++){
        int flag = 0;
        for(j=0; j< total-i-1; j++){
            if(array[j] > array[j+1]){
                //swap
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
    return array;
}

void main(){
    int i,total,number;

    printf("how many numbers?");
    scanf("%d",&total);

    int array[total];
    int* sorted;

    for(i=0 ; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        array[i] = number;
    }

    sorted = BubbleSort(array,total);

    for(int j=0 ; j<total; j++){
        printf("%d->",sorted[j]);
    }
}
