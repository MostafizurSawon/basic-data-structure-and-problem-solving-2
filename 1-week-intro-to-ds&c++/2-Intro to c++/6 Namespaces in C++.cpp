#include<bits/stdc++.h>

using namespace std;

namespace one
{
    int x = 10;
    void fun()
    {
        cout<<"I am one"<<endl;
    }
}

namespace two
{
    void fun3()
    {
        cout<<"I am two"<<endl;
    }
}

int main()
{
    cout<<one::x<<endl;

    return 0;
}
