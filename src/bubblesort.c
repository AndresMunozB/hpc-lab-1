// C program for implementation of Bubble sort 
#include <stdio.h> 
  
void swap(float *xp, float *yp) 
{ 
    float temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSort(float arr[], int n) 
{ 
    
   for (int i = 0; i < n-1; i++)       
       // Last i elements are already in place    
       for (int j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
  
/* Function to print an array */
void printArray(float arr[], int size) 
{ 
    
    for (int i=0; i < size; i++) 
        printf("%f ", arr[i]); 
    printf("\n"); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    float arr[] = {64.0, 34.0, 25.0, 12.0, 22.0, 11.0, 90.0}; 
    int n = 7;
    bubbleSort(arr, n); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
} 
