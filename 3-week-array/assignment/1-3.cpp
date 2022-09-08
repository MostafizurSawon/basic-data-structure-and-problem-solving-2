#include <bits/stdc++.h>
using namespace std;

void print (int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
    	cout<<arr[i]<<" ";
	}
}

int main()
{   int n;
cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
   	cin>> arr[i];
	}
	for(int i=1;i<n;i++)
	{  cout<<i<<" iteration:"<<endl;
    	int flag=0;
    	for(int j=0;j<n-i;j++)
    	{ cout<<"     	"<<j+1<<" step: ";
       	print(arr,n);
       	cout<<"-> ";
      	if(arr[j]>arr[j+1])
      	{
          	int temp=arr[j];
          	arr[j]=arr[j+1];
          	arr[j+1]=temp;
          	flag=1;
      	}
      	print(arr,n);
     	cout<<endl;
    	}

     	if(flag==0)
        	break;
	}
}
