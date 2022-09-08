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
    int array[50];
    int size;

    cin>>size;

    for(int i=0;i<size;i++)
    {
        cin>>array[i];
    }

    printArray(array, size);

    int pos, value;
    cout<<"Position of deletion: ";
    cin>>pos;

    if(pos < 0 || pos > size - 1)
    {
        cout<<"Invalid Index";
    }
    else
    {
        if(pos==size-1){
            size--; //last
        }
        else{
                //start or mid
            //pos+1 ---> size-1
            for(int i=pos+1;i<size;i++)
            {
                array[i-1] = array[i];
            }
            size--;
        }
    }

    cout<<"Array after deletion: ";
    printArray(array, size);

    return 0;
}
