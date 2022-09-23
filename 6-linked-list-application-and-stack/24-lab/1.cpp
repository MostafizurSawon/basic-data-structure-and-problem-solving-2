#include<bits/stdc++.h>
using namespace std;

int max(int arr[],int n)
{
    int max = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int n,i;
    cin>>n;
    int arr[n];

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    int freq[10] = {0};

    for(i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }

    int m = max(arr,n);

    for(i=0;i<=10;i++)
    {
        if(freq[i] != 0)
        {
            cout<<i<<" => "<<freq[i]<<endl;
        }
    }

    return 0;
}
