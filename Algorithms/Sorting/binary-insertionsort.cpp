#include<iostream>

using namespace std;


int binarySearch(int a[], int item, int low, int high) 
{ 
    if (high <= low) 
        return (item > a[low])?  (low + 1): low; 
  
    int mid = (low + high)/2; 
  
    if(item == a[mid]) 
        return mid+1; 
  
    if(item > a[mid]) 
        return binarySearch(a, item, mid+1, high); 
    return binarySearch(a, item, low, mid-1); 
} 
   
void insertionSort(int a[], int n) 
{ 
    int i, loc, j, k, selected; 
  
    for (i = 1; i < n; ++i) 
    { 
        j = i - 1; 
        selected = a[i]; 
  
        loc = binarySearch(a, selected, 0, j); 
  
        while (j >= loc) 
        { 
            a[j+1] = a[j]; 
            j--; 
        } 
        a[j+1] = selected; 
    } 
} 
  
int main() 
{ 

  	int arr[10] = {2,4,10,1,1,7,4,5,1,8};
    insertionSort(arr, 10); 
  
    printf("Sorted array: \n"); 
    for (int i = 0; i < 10; i++) 
        printf("%d ",arr[i]); 
  
    return 0; 
} 
