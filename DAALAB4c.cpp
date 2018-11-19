#include<bits/stdc++.h>
using namespace std;
 
int partition(int arr[], int l, int r, int k); 
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int n = h-l+1;
        int m=max(arr[l],max(arr[h],arr[(l+h)/2]));
        int mi=min(arr[l],min(arr[h],arr[(l+h)/2]));
        int med =0;
        if(arr[l]!=m && arr[l]!=mi)
            med=arr[l];
        else if(arr[h]!=m && arr[h]!=mi)
           med=arr[h];
        else
        med =arr[(l+h)/2];
        int p = partition(arr, l, h, med);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}
 
 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r, int x)
{
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
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
    //cout<<"\n"; 
    cout<<time_spent<<" time by quickSort \n";
    return 0;
}


//0.077848
//0.075209
//0.080063