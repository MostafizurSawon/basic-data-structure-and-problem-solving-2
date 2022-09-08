#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin>>x;

    while(x--)
    {
        int n,count,ans;
        count = 0;
        cin>>n;
        int array[n];

        for(int i=0;i<n;i++)
        {
            cin>>array[i];
        }

        int freq[1002] = {0},sum=0;

        for(int i=0; i<n; i++)
        {
            freq[array[i]]++;
            sum = max(array[i],sum);
        }

        int ts = freq[0];

        for(int i=0; i<=sum;i++)
        {
            ts = max(freq[i],ts);
        }

        ans = n - ts;

        cout<<ans<<endl;

    }

    return 0;
}
