#include<bits/stdc++.h>
using namespace std;

void printArray(int *array, int n)
{
 	for(int i=0; i<n; i++)
	{
        cout<<array[i]<<" ";
	}
    cout<<endl;
}

int main()
{
	int n, x;

	cin>>n;

	int array[n];

	for(int i=0; i<n; i++)
	{
    	cin>>array[i];
	}

	cout<<"Before Sorting:	";
	printArray(array, n);

	int count = 0;

	for(int i=0; i<n; i++)
	{
        count = max(array[i],count);
    }
    cout<<"Maximum Number is: ";
    cout<<count<<endl;

	int array2[count+1] = {0};

	for(int i=0; i<n; i++)
	{
    	array2[array[i]]++;
	}

	cout<<"Frequency Array : ";
    printArray(array2,count+1);


	for(int i=1; i<=count; i++)
	{
    	array2[i] = array2[i] + array2[i-1];
	}

	cout<<"Cumulative Sum: ";
	printArray(array2, count+1);


	int array3[n];

	for(int i=n-1; i>=0 ;i--)
	{
        x = --array2[array[i]];
        array3[x] = array[i];
	}
	cout<<"After Sorting: ";
	printArray(array3, n);

	return 0;
}

