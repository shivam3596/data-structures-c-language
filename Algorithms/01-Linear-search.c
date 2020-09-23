#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Time complexity O(n)

bool LinearSearch(int* array, int total, int find){
    for(int i=0; i<total; i++){
        if(array[i] == find) return true;
    }
    return false;
}

void main(){
    int i,total,number,find;

    printf("enter the total: ");
    scanf("%d",&total);

    int array[total];

    for(i=0; i<total; i++){
        printf("enter number: ");
        scanf("%d",&number);
        array[i] = number;
    }
    printf("enter the number you want to search: ");
    scanf("%d",&find);
    if(LinearSearch(array,total,find)){
        printf("Found !");
    }else{
        printf("Not Found !");
    }
}
