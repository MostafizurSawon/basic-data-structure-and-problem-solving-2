#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin>>a;

    int t = a/15;

    int sum = 800 * a;

    if(t>=1){
        sum = sum - t*200;
    }

    cout<<sum<<endl;


    return 0;
}

