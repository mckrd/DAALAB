#include<bits/stdc++.h>
using namespace std;

int bsearch(int arr[], int l, int r, int data)
{
   if (r >= l)
   {
        int mid = (l + r)/2;
 
        if (arr[mid] == data)  
            return mid;

        if (arr[mid] > data) 
            return bsearch(arr, l, mid-1, data);

        return bsearch(arr, mid+1, r, data);
   }
   return -1;
}

int bsearchiterative(int arr[],int n,int data)
{
	int l=0;
	int r=n-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(arr[mid]==data)
			return mid;
		else if (arr[mid]>data)
			r=mid-1;
		else l=mid+1;
	}
	return -1;

}
 

int main()
{	
	int n=1000000;
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i]=i;
	sort(arr,arr+n);
	
    clock_t begin = clock();
	int r=bsearch(arr,0,n-1,-1);
	clock_t end;
	end = clock();
   
	double time_spent = (double)(end - begin) / (CLOCKS_PER_SEC);
    cout<<"time taken by recursive "<<time_spent<<"\n";
	//cout<<"time taken by recursive "<<"1e-06\n";
	if(r)
		cout<<"found element\n";
	else
		cout<<"-1\n";

	begin = clock();
	r=bsearchiterative(arr,n,-1);
	end = clock();
 	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
     cout<<"time taken by iterative "<<time_spent<<"\n";

	if(r)
		cout<<"found element\n";
	else
		cout<<"-1\n";     
	return 0;
}