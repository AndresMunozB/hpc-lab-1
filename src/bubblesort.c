// C program for implementation of Bubble sort 
#include <stdio.h> 

void swap_float(float *xp, float *yp) 
{ 
    float temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubble_sort(float arr[], int n) 
{
    
   for (int i = 0; i < n-1; i++)       
       // Last i elements are already in place    
       for (int j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap_float(&arr[j], &arr[j+1]); 
}
  
