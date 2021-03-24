/*
By Yevgeniy Sumaryev
3/20/21
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;



void quickSortWithInsertSort(int arr[], int n);
void quickSort(int arr[], int n);

void swap(int *xp, int *yp){
    
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


//use insertion sort as a sort for the sorting
//of last 100 elements
void insertionSort(int* arr, int n){
    
    int insertKey, j;
    for (int i = 1; i < n; i++){
        insertKey = arr[i];
        j = i;
        //move array to the right until proper index is reached
        while (j > 0 && arr[j-1] > insertKey){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = insertKey;
    }
    
}


//partition array into 2 parts, part 1 is smaller than element
//at pivotIndex, and part 2 is bigger than element at pivotIndex 
void partition(int arr[], int n, int& pivotIndex){
    
    //use first element as pivot
    int pivot = arr[0];
    int tooBigIndex = 1;
    int tooSmallIndex = n - 1;
    
    //keep moving from opposite direction and 
    //swap elements whenever smaller element is on the right
    //and bigger element is on the left side of the pivot element
    while (tooBigIndex <= tooSmallIndex){
        while (tooBigIndex < n && arr[tooBigIndex] <= pivot){
            tooBigIndex++;
        }
        while (arr[tooSmallIndex] > pivot){
            tooSmallIndex--;
        }
        if(tooBigIndex < tooSmallIndex)
            swap(&arr[tooBigIndex], &arr[tooSmallIndex]);
    }
    
    //move pivot to correct position
    pivotIndex = tooSmallIndex;
    arr[0] = arr[pivotIndex];
    arr[pivotIndex] = pivot;
    
}

//Implmentation of quicksort with insertion sort
//use quicksort as the main sort whenever number of elements are > 100
//when number of element < 100 use insertion sort
void quickSortWithInsertSort(int arr[], int n){
    
    int pivotIndex;
    int beforePivot;
    int afterPivot;
    
    if (n>1){
        //partition array
        partition(arr, n, pivotIndex);
        
        //compute sizes of subarrays
        beforePivot = pivotIndex;
        afterPivot = n - beforePivot - 1;

        //if the size of array is less than 100
        //use insertion sort to sort the rest of the array 
        //the program will enter this part when number of 
        //elements is less than 100
        if(n<100){
            //sort array from the beginning to beforeIndex element
           insertionSort(arr, beforePivot);
           //sort array from the element after pivotIndex to the last element
           insertionSort(arr+pivotIndex+1, afterPivot);
        }

        //sort subarrays
        quickSortWithInsertSort(arr, beforePivot);
        quickSortWithInsertSort(arr+pivotIndex+1, afterPivot);
    }
}


//use normal quicksort for comparison
void quickSort(int arr[], int n){
    
    int pivotIndex;
    int beforePivot;
    int afterPivot;
    
    if (n>1){
        //partition array
        partition(arr, n, pivotIndex);
        
        //compute sizes of subarrays
        beforePivot = pivotIndex;
        afterPivot = n - beforePivot - 1;

        //sort subarrays
        quickSort(arr, beforePivot);
        quickSort(arr+pivotIndex+1, afterPivot);
    }
}

int main(int argc, const char * argv[]) {
    
    //initialize array with 100000 elements
    int anyArray[100000];

    /* initialize random seed: */
    srand(time(NULL));
    
    //populate the array with random ints 1-100
    for (int i = 0; i < 100000; i++)
    {
        anyArray[i] = rand() % 100 + 1;
    }
    
    //get size of the array
    int arraySize = sizeof(anyArray)/sizeof(anyArray[0]);
    
     //variable to time the function
    auto start = chrono::system_clock::now();
    
    //first use normal quicksort to sort
    quickSort(anyArray, arraySize);
    
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    cout << "Normal quicksort elapsed time: " << elapsed_seconds.count() << "s\n";

    /* initialize random seed: */
    srand(time(NULL));
    
    //populate the array with random ints 1-100
    for (int i = 0; i < 100000; i++)
    {
        anyArray[i] = rand() % 100 + 1;
    }

    arraySize = sizeof(anyArray)/sizeof(anyArray[0]);
    //variable to time the function
    start = chrono::system_clock::now();
    
    //Use a sort from standard library to compare
    sort(anyArray, anyArray + arraySize);
    
    end = chrono::system_clock::now();
    elapsed_seconds = end-start;
    cout << "Sort from standard library elapsed time: " << elapsed_seconds.count() << "s\n";

    /* initialize random seed: */
    srand(time(NULL));

    //populate the array with random ints 1-100
    for (int i = 0; i < 100000; i++)
    {
        anyArray[i] = rand() % 100 + 1;
    }

    //variable to time the function
    start = chrono::system_clock::now();
    //now use quickSort with InsertSort to sort the array 
    quickSortWithInsertSort(anyArray, arraySize);
    end = chrono::system_clock::now();
    elapsed_seconds = end-start;
    cout << "quicksort with insertion sort elapsed time: " << elapsed_seconds.count() << "s\n";



    // cout << "Contents of the sorted array: " << endl;
    // for (int i = 0; i < arraySize; i++)
    // {
    //     cout << anyArray[i] << " ";
    // }
    
    cout<<endl;

    return 0;
}
