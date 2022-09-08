#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Sawon";
    string::iterator it;
    for(auto it=s.rbegin(); it!=s.rend();it++)
    {
        cout<<*it<<endl;
    }
    cout<<s<<endl;

    return 0;
}

