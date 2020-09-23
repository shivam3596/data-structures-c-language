#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool BinarySearchRecursive(int* array, int start, int end, int find){
    if(start > end) return false;

    int mid = start+(end-start)/2;

    if(find == array[mid]){
        return true;
    }else if(find < array[mid]){
        return BinarySearchRecursive(array,start,mid-1,find);
    }else{
        return BinarySearchRecursive(array,mid+1,end,find);
    }
}

void main(){
    int i,total,number,find;

    printf("enter total: ");
    scanf("%d",&total);

    int start = 0;
    int end = total -1;
    int array[total];

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        array[i] = number;
    }

    printf("enter the number you want to search: ");
    scanf("%d",&find);

    if(BinarySearchRecursive(array,start,end,find)){
        printf("Found !");
    }else{
        printf("Not Found !");
    }
}
