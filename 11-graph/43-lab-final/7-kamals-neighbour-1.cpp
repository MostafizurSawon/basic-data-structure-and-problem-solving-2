#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e,k;
    cin>>n>>e;

    int ans = 0;
    vector<vector<int>> adj(n, vector<int>());

    for(int i=0; i<e; i++)
    {
        int x,y;
        cin>>x>>y;

        adj[x].push_back(x);
        adj[y].push_back(y);
    }

    cin>>k;
    ans = adj[k].size();
    cout<<ans<<endl;

    return 0;
}
