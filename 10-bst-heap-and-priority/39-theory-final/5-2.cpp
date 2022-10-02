#include <bits/stdc++.h>
using namespace std;
/*
Min Heap : 5 -> 20 -> 15 -> 50 -> 30 -> 40

step 1 : 15 -> 20 -> 40 -> 50 -> 30 -> 5
step 2 : 20 -> 30 -> 40 -> 50 -> 15 -> 5
step 3 : 30 -> 50 -> 40 -> 20 -> 15 -> 5
step 4 : 40 -> 50 -> 30 -> 20 -> 15 -> 5

*/

void minHeapify(int array[], int n, int current)
{
    int left = 2*current + 1, right = 2*current + 2, min = current;

    if(left < n && array[left] < array[min])
    {
        min = left;
    }

    if(right < n && array[right] < array[min])
    {
        min = right;
    }

    if (min != current)
    {
        swap(array[min], array[current]);
        minHeapify(array, n, min);
    }
}


void print(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void heapSort(int array[], int n)
{
    for (int i=1; i<n; i++)
    {
        cout<<"Step "<<i<<" : ";
        print(array, n);

        swap(array[0], array[n-i]);
        minHeapify(array, n-i-1, 0);
    }
}

int main()
{
    int n;
    cin >> n;
    int array[n];

    for(int i=0; i<n; i++)
    {
        cin >> array[i];
    }

    int nonLeafStart = (n/2) - 1;

    cout<<endl;
    print(array, n);

    for (int i=nonLeafStart; i>=0; i--)
    {
        minHeapify(array, n, i);
    }

    cout<<"After heapifying: ";

    print(array, n);

    cout<<endl;

    heapSort(array, n);

    cout<<endl;

    cout<<"After Heap Sorting: ";
    print(array, n);

    return 0;
}

/*
6
20 50 40 5 30 15

*/

