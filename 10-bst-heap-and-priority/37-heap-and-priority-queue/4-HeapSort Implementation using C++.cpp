#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int n,int current)
{
    int largest = current;
    int leftChild = 2*current + 1;
    int rightChild = 2* current + 2;

    if(leftChild < n && array[leftChild] > array[largest])
    {
        largest = leftChild;
    }
    if(rightChild < n && array[rightChild] > array[largest])
    {
        largest = rightChild;
    }
    if(largest != current)
    {
        swap(array[current], array[largest]);
        heapify(array, n, largest);
    }

}

void printArray(int array[], int size)
{
    cout<<endl;
    for(int i =0; i<size; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void heapsort(int array[], int size)
{
    for(int i = size - 1,j=1; i>=0,j<size; i--,j++)
    {
        swap(array[0], array[i]);

        //print the array
        cout<<"Iteration "<<j<<": ";
    	printArray(array, size);

        heapify(array, i, 0);
    }
}

int main()
{
    int n;
    cin>>n;
    int array[n];

    for(int i=0; i<n; i++)
    {
        cin>>array[i];
    }

    cout<<"Before Heapify: ";
    printArray(array, n);

    //Heapifiy
    int nonLeafStart = (n/2)-1;

    for(int i=nonLeafStart; i>=0; i--)
    {
        heapify(array, n ,i);
    }
    cout<<endl;
    cout<<"After Heapify: ";
    printArray(array, n);

    heapsort(array,n);

    cout<<endl;
    cout<<"After heapsort : ";
    printArray(array,n);

    return 0;
}

/*
9
2 10 1 5 4 8 3 8 7

*/

