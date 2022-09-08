#include <bits/stdc++.h>
using namespace std;

int i=1;

int binarySearch(int a[], int lb, int ub, int x)
{
 	int mid = (lb + ub) / 2;
 	cout<<"step: "<<i<<endl;
 	cout<<"lower bound= "<<lb<<endl;
 	cout<<"upper bound= "<<ub<<endl;
 	cout<<"mid= "<<mid<<endl;
 	cout<<"array[mid]= "<<a[mid]<<endl;

 	if(lb <= ub)
   	{
        if(a[mid] == x)
        {
            return mid;
        }

        else if(a[mid] < x)
        {
            i++;
            binarySearch(a, mid + 1, ub, x);
        }

        else
        {
            i++;
            binarySearch(a, lb, mid - 1, x);
        }
  	}

  	else
    {
    	return -1;
    }
 }

 int main()
 {
 	int a[] = {1, 2, 9, 11, 17, 24, 26, 31, 32, 45};
 	int lenth = sizeof(a) / sizeof(a[0]);
 	int index= binarySearch(a, 0, lenth-1,6);

 	cout<<endl<<endl;

 	if(index ==-1)
 	{
        cout<< "Sorry Not found :(" ;
 	}
 	else
    {
        cout<<"Found at index: "<<index;
    }
    cout<<endl<<endl;
 }

