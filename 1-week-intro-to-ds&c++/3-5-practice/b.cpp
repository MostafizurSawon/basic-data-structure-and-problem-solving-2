#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[100000];
    cin>>a;

    for(int i=0;i<strlen(a);i+=2)
    {
        cout<<a[i];
    }

    return 0;
}

