#include<bits/stdc++.h>
#include"mystack.h"
using namespace std;
/*
stack of float,double,array,structure, object of class
*/

int main()
{
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);

    /*
    while(!st.empty())
    {
        cout << st.pop() <<endl;
    }
    */

    cout<< st.size()<<endl;
    if(st.empty())
    {
        cout<<st.Top()<<endl;
    }

    return 0;
}

