#include<stdio.h>
#include<stdlib.h>

//in heap sort:
//first build heap by following max-heap property
//delete root node from heap by following max-heap property
//in the end ,array will be sorted

//Time complexity of heapify is O(Logn). Time complexity of createAndBuildHeap() is O(n) and overall time complexity of Heap Sort is O(nLogn)

void Heapify(int* array, int total, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    //if left child is greater then swap with parent
    if(left< total && array[left] > array[largest]){
        largest = left;
    }

    //if right child is greater the swap with parent
    if(right < total && array[right] > array[largest]){
        largest = right;
    }

    if(largest != i){
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        //recursively heapift affected subtree
        Heapify(array,total,largest);
    }
}

void BuildHeap(int* array, int total){
    //last non-leaf node
    int lastNonLeafNode = (total/2)-1;

    //reverse order traversal from last-non leaf node and heapify each node
    for(int i= lastNonLeafNode; i>=0; i--){
        Heapify(array,total,i);
    }

    //extract element from heap
    for(int j= total-1; j>= 0; j--){
        //swap element with root
        int temp = array[0];
        array[0] = array[j];
        array[j] = temp;

        // call max heapify on the reduced heap
        Heapify(array, j, 0);
    }
}

void PrintHeap(int* array, int total)
{
    for (int i = 0; i < total; ++i){
        printf("%d-> ",array[i]);
    }
    printf("\n");
}

void main(){
    int i,total,number;

    printf("how many numbers you want to insert?");
    scanf("%d",&total);

    int array[total];

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        array[i] = number;
    }

    BuildHeap(array,total);
    PrintHeap(array,total);
}
