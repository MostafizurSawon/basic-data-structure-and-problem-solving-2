#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;

    int ans = 1;

    if(a!=b && b!=c && a!=c)
    {
        ans = 3;
    }
    else if(a==b && a!=c)
    {
        ans = 2;
    }
    else if(a!=b && a==c)
    {
        ans = 2;
    }
    else if(a!=b && b==c)
    {
        ans = 2;
    }

    cout<<ans;

    return 0;
}

/*



*/
