#include<stdio.h>
#include<stdlib.h>

//Time complexity O(log n)

//if we do linear search for counting occurance then it will give O(n)

int FirstOccurance(int* array, int total, int find){
    int start = 0;
    int end = total - 1;
    int result = -1;

    while(start <= end){
        int mid = start+(end-start)/2;

        if(find == array[mid]){
            result = mid;
            end = mid - 1;
        }else if(find < array[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return result;
}

int LastOccurance(int* array, int total, int find){
    int start = 0;
    int end = total - 1;
    int result = -1;

    while(start <= end){
        int mid = start+(end-start)/2;

        if(find == array[mid]){
            result = mid;
            start = mid + 1;
        }else if(find < array[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return result;
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

    //count of element in sorted array will be difference between last and first occurance of element
    if(FirstOccurance(array,total,find) == -1){
        printf("occurance count is : %d\n",0);
    }else{
        printf("occurance count is : %d\n",(LastOccurance(array,total,find) - FirstOccurance(array,total,find)) + 1);
    }
}
