#include<stdio.h>
#include<stdlib.h>

//all elements are distinct and array is sorted
//how many times sorted array is rotated is = Index of the min element in array
//Time complexity O(log n)

int RotatedCount(int* array, int total){
    int start = 0;
    int end = total - 1;

    while(array[start] > array[end]){
        int mid = start + (end-start)/2;
        int next = mid + 1;
        int prev = mid - 1;

        //case 1: if next and prev elements are greater than the mid element then we have found the pivot element
        if(array[mid] < array[next] && array[mid] < array[prev]){
            return mid;
        }
        //Case 2: check if right half segment is sorted, if right half is sorted then min element will be on left half
        else if(array[mid] < array[end]){
            end = mid - 1;
        }
        //Case 3: check if left half segment is sorted, if left half is sorted then min element will be on right half
        else if(array[mid] > array[start]){
            start = mid + 1;
        }
    }
    //if array is already sorted
    return start;
}

void main(){
    int i,total,number;

    printf("enter total: ");
    scanf("%d",&total);

    int array[total];

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        array[i] = number;
    }

    printf("array is rotated %d times",RotatedCount(array,total));
}
