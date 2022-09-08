#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "SawonIsMyName";

    cout<<s.find('m')<<endl;
    cout<<s.find_first_not_of('m')<<endl;
    cout<<s.find_last_not_of('m')<<endl;
    cout<<s.substr(2,5)<<endl;

    return 0;
}


