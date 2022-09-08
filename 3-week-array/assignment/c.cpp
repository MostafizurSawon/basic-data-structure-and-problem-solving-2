#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin>>x;

    while(x--)
    {
        int n,sum,ans;
        sum = 0;
        cin>>n;
        int array[n];

        for(int i=0;i<n;i++)
        {
            cin>>array[i];
        }

        //make sort
        sort(array,array+n);

        for(int i=0; i<n-1; i++)
        {
            if(array[i] == array[i+1])
            {
                sum++;
            }
            else
            {
                break;
            }
        }

        ans = n - (sum + 1);
        cout<<ans<<endl;

    }

    return 0;
}
