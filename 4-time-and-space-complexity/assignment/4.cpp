#include<bits/stdc++.h>

using namespace std;

void print(int *arr,int n)
{
 	for(int i=0;i<n;i++)
	{
  	cout<<arr[i]<<" ";
	}
   cout<<endl;
}

int main()

{
	int n,k,p;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
	{
    	cin>>arr[i];
	}
	cout<<"Before Sort:	";
	print(arr,n) ;
	int coun=0;
	for(int i=0;i<n;i++)
	{ coun= max(arr[i],coun);}
	cout<<"Maximum Number: ";
	cout<<coun<<endl;


	int arr2[coun+1]={0};
	for(int i=0;i<n;i++)
	{
    	arr2[arr[i]]++;
	}
	cout<<"Frequency:  	";
   print(arr2,coun+1) ;


	for(int i=1;i<=coun;i++)
	{
    	arr2[i]=arr2[i]+arr2[i-1];
	}
	cout<<"Cumulative Sum: ";
	print(arr2,coun+1) ;

	int arr3[n];

	for(int i=n-1;i>=0;i--)
	{
 	p= --arr2[arr[i]];

  	arr3[p]=arr[i];

	}
	cout<<"After Sort: 	";
	print(arr3,n);



}
