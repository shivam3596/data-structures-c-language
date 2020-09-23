#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Time Complexity O(log n)

bool BinarySearch(int* array,int total, int find){
    int start = 0;
    int end = total-1;

    while(start <= end){
        int mid = start + (end - start)/2; //used this in case of overflow condtion for large integer numbers
        //int mid = (start+end)/2;

        if(find == array[mid]){
            return true;
        }else if(find < array[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return false;
}

void main(){
    int i,total,number,find;

    printf("enter the total: ");
    scanf("%d",&total);

    int array[total];

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        array[i] = number;
    }

    printf("enter the number you want to search: ");
    scanf("%d",&find);

    if(BinarySearch(array,total,find)){
        printf("Found !");
    }else{
        printf("Not Found !");
    }
}
