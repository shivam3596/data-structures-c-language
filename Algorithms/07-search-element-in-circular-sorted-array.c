#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


bool FindElement(int* array, int total, int find){
    int start = 0;
    int end = total - 1;

    while(start <= end){
        int mid = start+(end-start)/2;

        if(find == array[mid]){
            return true;
        }
        //check if right half is sorted
        else if(array[mid] <= array[end]){
            if(find <= array[end] && find > array[mid]){
                start = mid + 1; //search in right half
            }else{
                end = mid - 1;//go to left half
            }
        }

        else{
            if(find < array[mid] && find >= array[start]){
                end = mid - 1; //search in left half
            }else{
                start = mid + 1; //go to right half
            }
        }
    }
    return false;
}

void main(){
    int i,total,number,find;

    printf("enter total: ");
    scanf("%d",&total);

    int array[total];

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        array[i] = number;
    }

    printf("enter the number you want to search: ");
    scanf("%d",&find);

    if(FindElement(array,total,find)){
        printf("Found !");
    }else{
        printf("Not Found !");
    }
}
