#include<bits/stdc++.h>

using namespace std;

int main()
{
	
	int n=5;
	pair<int,pair<int,string> > arr[n];
	bool slot[n];
	int result[n];
	for(int i=0;i<n;i++)
	{
		arr[i].second.second=65+i;
		cout<<"Enter deadline for "<<i+1<<" job\n";
		cin>>arr[i].second.first;
		cout<<"Enter profit for "<<i+1<<" job\n";
		cin>>arr[i].first;
		slot[i]=false;
	}
	sort(arr,arr+n);
	for(int i=0;i<n/2;i++)
		swap(arr[i],arr[n-1-i]);
	

	for(int i=0;i<n;i++)
	{
		for(int j=(n,arr[i].second.first)-1;j>=0;j--)
		{
			if(slot[j]==false)
			{
				result[j]=i;
				slot[j]=true;
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
		if(slot[i])
			cout<<arr[result[i]].second.second<<" ";

	return 0;
}