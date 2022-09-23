#include<bits/stdc++.h>
using namespace std;


void compare(int array1[],int array2[],int counter,int counter2)
{
    int flag=0;
    for (int i=0; i<counter; i++)
   {
       flag=0;
        for(int o=0; o<counter2; o++)
       {
            if (array1[i]==array2[o])
            flag=1;
       }
       if (flag==0)
       cout<<array1[i]<<endl;
    }
}


int main()
{
    int n,m,i,j;
    cin>>n;
    int arr[n];


    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cin>>m;
    int arr2[m];

    for(i=0;i<m;i++)
    {
        cin>>arr2[i];
    }


    //cout<<x;

    int ans;
    for(i=0;i<n;i++)
    {
        ans = 0;
        for(j=0; j<m; j++)
        {
            if(arr[i] == arr2[j])
            {
                ans = 1;
            }
        }
        if (ans == 0)
        {
            cout<<arr[i]<<" ";
        }
    }

    return 0;
}



/*
int main()
{
  int array1[8]={100,110,120,100,102,100, 106, 109};
  int array2[4]={100,110,120,100};
  compare(array1,array2,8,4);
    return 0;
}


*/
