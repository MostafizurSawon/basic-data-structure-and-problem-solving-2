#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,n;
    cin>>n;

    a = n/100;
    b = n/10-a*10;
    c = n-a*100-b*10;

    if(a == c)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;
}
