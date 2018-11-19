#include<bits/stdc++.h>
using namespace std;

int main()
{
	int p[5],pos=0;
	
	int input[5][5]={{0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}}; 
  
	int I[5]={0,0,0,0,0};
	int key[5]={10,10,10,10,10};
	
	for(int k=0;k<5;k++)
	{
		I[pos]=1;//include hogyi,
		p[0]=-1;//parent
		for(int i=0;i<5;i++)
		{	//honi bhi chahiye		//already se less		//not already incident
			if(input[pos][i]!=0 && input[pos][i]<key[i] && I[i]==0)
				key[i]=input[pos][i];//wt min
    	}
   
   		int min=key[0];
   		for(int i=1;i<5;i++)//choose best 
   		{
   	 		if(I[i]==0 && key[i]<min)
   			{ 
   				pos=i;
				min=key[i];
    		}
   		}
		for(int i=0;i<5;i++)//jahan match woh parent
		{
			if(input[pos][i]==min && I[i]==1)
				p[pos]=i;
		}
	}
	cout<<"parents for vertices 1 to 5\n";
	for(int i=0;i<5;i++)
		cout<<p[i]+1<<"   ";
	cout<<"\n";
	cout<<"their respective weights\n";
	key[0]=0;
	for(int i=0;i<5;i++)
		cout<<key[i]<<"   ";

	return 0;
}