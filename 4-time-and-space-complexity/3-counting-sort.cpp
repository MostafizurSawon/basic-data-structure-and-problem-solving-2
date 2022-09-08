#include<bits/stdc++.h>
using namespace std;

void printArray(int array[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int size;
    cin>>size;

    int array[size];

    for(int i=0;i<size;i++)
    {
        cin>>array[i];
    }

    cout<<"BEfore Sort: ";
    printArray(array,size);

    //Step 1
    int max = INT_MIN;
    for(int i=0; i<size; i++)
    {
        if(array[i]>max)
        {
            max = array[i];
        }
    }

    //Step 2    //Initialization of 'count' array
    int count[max+1];

    for(int i=0; i<=max; i++)
    {
        count[i] = 0;
    }

    //Step 3
    for(int i=0;i<size;i++)
    {
        count[array[i]]++;
    }

    cout<<"Frequncy :      ";
    printArray(count,max+1);

    //Step 4    //cumulative sum
    for(int i=0; i<=max; i++)
    {
        count[i] += count[i-1];
    }

    cout<<"Cumulative Sort: ";
    printArray(count,max+1);

    //step 5    final array ----> backward traversal of basic Array
    int final[size];

    for(int i=size-1;i>=0;i--)
    {
        count[array[i]]--;
        int k = count[array[i]];
        final[k] = array[i];
    }

    cout<<"After Sort: ";
    printArray(final,size);

    return 0;
}
