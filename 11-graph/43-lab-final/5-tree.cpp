#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;

    long long tree = pow(2, n-1);
    long long int sum = tree/2;

    long long ans = sum * tree;

    if(n == 1)
    {
        ans = 1;
    }

    cout<<ans<< endl;

    return 0;
}
