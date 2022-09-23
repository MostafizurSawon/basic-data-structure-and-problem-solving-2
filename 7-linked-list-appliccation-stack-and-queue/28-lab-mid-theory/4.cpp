#include<bits/stdc++.h>
using namespace std;

int binarySearch(int array[], int x, int lb, int ub)
{
    if(lb<=ub)
    {
        int mid = (lb+ub)/2;
        //x==arr[Mid]
        if(x==array[mid])   return mid;//Centre

        else if(x>array[mid])   binarySearch(array,x,mid+1,ub);//right

        else binarySearch(array,x,lb,mid-1); //left
    }
    else  return -1;
}

int main()
{
    int array[] = {1,2,4,9,12,14,16,21,32,35};
    int size = sizeof(array)/sizeof(array[0]);

    int checkValue = 4;

    int indexNumber;
    indexNumber = binarySearch(array,checkValue,0,size-1);

    if(indexNumber!=-1)
    {
        cout<<"Found at "<<endl<<"Index  No   : "<<indexNumber<<"\n"<<"Position No : "<<indexNumber+1<<endl;
    }
    else
    {
        cout<<"Not found!"<<endl;
    }

    return 0;
}

//No duplicate value
//Sorted Array must


