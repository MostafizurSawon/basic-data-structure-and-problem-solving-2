#include<bits/stdc++.h>
#include"mstack.h"
using namespace std;
/*
stack of float,double,array,structure, object of class
*/

int main()
{

    Stack <int> st;

    st.push(2);
    st.push(4);
    st.push(6);

    while(!st.empty())
    {
        cout<<st.mid()<<endl;
        break;
    }

    return 0;
}

