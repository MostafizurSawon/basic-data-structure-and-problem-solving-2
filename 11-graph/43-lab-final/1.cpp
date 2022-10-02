#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int a,b,sum = 0;
        cin>>a>>b;

        int array[n];
        for(int j=0; j<a; j++)
        {
            cin>>array[j];
            sum += array[j]*2;
        }
        if(b-sum>=0)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }

    return 0;
}
