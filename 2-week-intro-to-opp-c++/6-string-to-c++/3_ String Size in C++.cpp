#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "SawonIsMyName";

    cout<<s<<" "<<s.size()<<endl;
    s.resize(4);
    cout<<s<<" "<<s.size()<<endl;

    //s.clear();
    if(s.empty())
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;
}

