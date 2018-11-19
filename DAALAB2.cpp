 #include<bits/stdc++.h>
using namespace std;

void iSort(int arr[], int n)
{
   int insert, j;
   for (int i = 1; i < n; i++)
   {
       insert = arr[i];
       j = i-1;
 
       while (j >= 0 && arr[j] > insert)
       {
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = insert;
   }
}

void sSort(int arr[], int n)
{
    int j, minimum;
 
    for (int i = 0; i < n-1; i++)
    {
        minimum = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[minimum])
            minimum = j;

        int t =arr[minimum];
        arr[minimum]=arr[i];
        arr[i]=t;
    }
}

int main()
{
	int n=20;
	int arr[n];
	srand(time(0));
	for(int i=0;i<n;i++)
		arr[i]= rand()%100;
	clock_t begin = clock();
	sSort(arr,n);
	clock_t end;
	end = clock();
	double time_spent = (double)(end - begin) / (CLOCKS_PER_SEC);
	cout<<"time taken by selection sort "<<time_spent<<"\n";
	//cout<<"time taken by selection sort 1e-06 \n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
		cout<<"\n";
	srand(time(0));
	for(int i=0;i<n;i++)
		arr[i]=rand()%100;
	begin = clock();
	iSort(arr,n);	
	end = clock();
	time_spent = (double)(end - begin) / (CLOCKS_PER_SEC);
	cout<<"time taken by insertion sort "<<time_spent<<"\n";
	//cout<<"time taken by insertion sort 1e-06 \n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
		cout<<"\n";

	return 0;
}