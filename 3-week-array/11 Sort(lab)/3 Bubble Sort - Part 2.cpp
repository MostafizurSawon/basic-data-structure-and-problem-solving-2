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

    for(int i=0; i<size; i++)
    {
        cin>>array[i];
    }

    cout<<"Before Sort : ";
    printArray(array, size);

    //bubble sort implementation
    for(int i=1;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            //if(array[j]>array[j+1])
            if(array[j]<array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    cout<<"After Sort : ";
    printArray(array, size);

    return 0;
}


