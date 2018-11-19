#include<bits/stdc++.h>
using namespace std;
 
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
 
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 
int partition_r(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
 
    return partition(arr, low, high);
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition_r(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
int main()
{
    int n=100000;
    int arr[n];
    srand(time(0));
    for(int i=0;i<n;i++)
        arr[i]= rand()%100;
    clock_t begin = clock(),end;
    quickSort(arr,0,n-1);
    end=clock();
    double time_spent = (double)(end - begin) / (CLOCKS_PER_SEC);
    //for(int i=0;i<n;i++)
      //  cout<<arr[i]<<" ";
    //     cout<<"\n"; 
    cout<<time_spent<<" time by quickSort \n";
    return 0;
}

//0.212016 

//0.200013

//0.210013