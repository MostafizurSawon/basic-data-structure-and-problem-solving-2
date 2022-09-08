#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int sum = 0;

    int left = a - b;

    if(a>b)
    {
        sum = b * c + left *d;
    }
    else{
        sum = a*c;
    }

    cout<<sum<<endl;

    return 0;
}
