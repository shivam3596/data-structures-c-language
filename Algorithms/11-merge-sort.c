#include<stdio.h>
#include<stdlib.h>

//Time complexity O(n log n)

void Merge(int* leftArray, int* rightArray, int* array, int leftLength, int rightLength){
    int i=0,j=0,k=0; //i for leftArray, j for rightArray , k for main array

    //compare smallest element from left and right array and replace with main array index
    while(i < leftLength && j < rightLength){
        if(leftArray[i] < rightArray[j]){
            array[k] = leftArray[i];
            i++;
        }else{
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    //in odd length of main array...some elemets will be remaining in left or right array ...so fill those elements in main array
    while(i < leftLength){
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while(j < rightLength){
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void MergeSort(int* array, int total){
    int i,mid,*leftArray,*rightArray;

    //base condition for recursion
    if(total < 2) return;

    mid = total/2;
    leftArray = (int*)malloc(mid*sizeof(int));
    rightArray = (int*)malloc((total-mid)*sizeof(int));

    //fill elements in left and right arrays
    for(i=0; i<mid; i++){
        leftArray[i] = array[i];
    }
    for(i=mid; i<total; i++){
        rightArray[i-mid] = array[i];
    }
    MergeSort(leftArray, mid);
    MergeSort(rightArray, total-mid);
    Merge(leftArray,rightArray,array,mid,total-mid);
    free(leftArray);
    free(rightArray);
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

    MergeSort(array,total);

    for(int j=0; j<total; j++){
        printf("%d->",array[j]);
    }
}
