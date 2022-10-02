#include <bits/stdc++.h>
using namespace std;

void heapify(int array [],int n,int i)
{
	int smallest = i;
	int leftChild = (2*i)+1;
	int rightChild = (2*i)+2;

    if(leftChild < n && array[leftChild] < array[smallest])
    {
        smallest = leftChild;
    }

    if(rightChild < n && array[rightChild] < array[smallest])
    {
        smallest = rightChild;
    }

    if(smallest != i)
    {
        swap(array[smallest],array[i]);
        heapify(array,n,smallest);
    }
}

void printArray(int array[],int n)
{
 	for(int i=0;i<n;i++)
  	{
    	cout<<array[i]<<" ";
  	}
	cout<<endl;
}

void heapsort(int array[],int n)
{
	for(int i=n-1,j=1; i>=0,j<n; i--,j++)
	{
    	swap(array[i],array[0]);

    	//Each iteration
    	cout<<"Iteration "<<j<<": ";
    	printArray(array,n);
    	heapify(array,i,0);
	}
}


int main()
{
    int array[] = {20,50,40,5,30,15};
    int n = sizeof(array) / sizeof(array[0]);

    int nonLeafStart=(n/2)-1;

    for(int i=nonLeafStart; i>=0 ;i--)
    {
        heapify(array,n,i);
    }

    printArray(array,n);

    heapsort(array,n);

    cout<<"After heapSort : ";
    printArray(array,n);

	return 0;
}

/*
6
20 50 40 5 30 15

*/
