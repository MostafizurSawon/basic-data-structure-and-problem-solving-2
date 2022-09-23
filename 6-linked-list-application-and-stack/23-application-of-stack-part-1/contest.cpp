#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a,a+n);
    cout<<a[0]+a[1];


    return 0;
}


/*
    int n,s,p;
    cin>>n;
    s = n/2;
    p = 1;

    for(int i=1;i<=n;i+=2)
    {
        for(int k=0;k<s;k++)
        {
            cout<<" ";
        }
        s--;

        for(int j=0;j<i;j++)
        {

            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=n-2;i>=0;i-=2)
    {
        for(int k=1;k<=p;k++)
        {
            cout<<" ";
        }
        p++;
        for(int j=0;j<i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
//pattern print





    int n,ans = 0;
    cin>>n;
    char s[n];

    for(int i=0; i<n; i++)
    {
        cin>>s[i];
       // cout<<s[i]<<endl;
    }
    int count = 0;
    int count2 = 0;

    for(int i=0; i<n; i++)
    {
        if(s[i] == '-')
        {
            count2 = 0;
            count++;
            //ans++;
        }
        if(count>ans)
        {
            ans = count;
            //count = 0;
        }
        if(s[i] == '+')
        {

            count2++;
            count = 0;
        }
        if(count2>ans)
        {
            ans = count2;
        }

    }
    cout<<ans;






        int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int min1=a[0];
    int min2=a[1];

    for(int i=1;i<n;i++)
    {
        if(min1>a[i])
        {
            min1 = a[i];
        }
    }
    int t = 0;

    for(int i=0;i<n;i++)
    {
        if(a[i] == min1)
        {
            t++;
        }
        if(min2>a[i] && a[i]>min1)
        {
            min2 = a[i];
        }

        if(t>=2)
        {
            min2 = min1;
        }
    }
    cout<<min1+min2<<endl;
*/
