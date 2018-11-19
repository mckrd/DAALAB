#include<bits/stdc++.h>
using namespace std;

int main()
{
	pair<double,pair<double,double> > arr[3];

	int w=50;
	int presentw=0;
	double fp=0;
	for(int i=0;i<3;i++)
	{
		cout<<"Enter profit of "<<i+1<<" item\n";
		cin>>arr[i].second.first;
		cout<<"Enter weight of "<<i+1<<" item\n";
		cin>>arr[i].second.second;
	}
	for(int i=0;i<3;i++)
		arr[i].first=arr[i].second.first/arr[i].second.second;

	sort(arr,arr+3);

	for(int i=0;i<1;i++)
		swap(arr[i],arr[3-i-1]);	

	for(int i=0;i<3;i++)
	{
		if(presentw+arr[i].second.second<=w)
		{
			presentw+=arr[i].second.second;
			fp+=arr[i].second.first;
		}
		else
		{
			int rem=w-presentw;
			fp+=arr[i].second.first*(rem/arr[i].second.second);
			break;
		}
	}

	cout<<"Maximum possible profit is "<<fp<<"\n";

	return 0;
}