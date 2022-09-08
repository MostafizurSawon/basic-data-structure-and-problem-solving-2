#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[50001];

    for(int i=0;i<n;i++)
    {
        int m,pos;
        cin>>m>>pos;

        int array[m];

        for(int i=0; i<m; i++)
        {
            cin>>array[i];
        }

        for(int i=0; i<pos; i++)
        {
            int i1,j1;
            cin>>i1>>j1;

            int ans = array[i1-1];
            if(ans>array[j1-1])
            {
                ans = array[j1-1];
            }
            arr[i] = ans;
        }
        cout<<"Case "<<i+1<<":"<<endl;

        for(int i=0;i<pos;i++)
        {
            cout<<arr[i]<<endl;
        }
    }

    for(int i=0;i<n;i++)
    {

    }


    return 0;
}

/*



*/
