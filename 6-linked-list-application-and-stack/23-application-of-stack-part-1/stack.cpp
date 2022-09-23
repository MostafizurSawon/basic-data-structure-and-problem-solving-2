#include<bits/stdc++.h>
#include"mystack.h"
using namespace std;
/*
stack of float,double,array,structure, object of class
*/

int main()
{
    /*
    Stack <float> st;

    st.push(1.3);
    st.push(2.4);
    st.push(3.7);
    */

    /*
    Stack <string> st;

    st.push("SawOn");
    st.push("Firefist Ace");
    st.push("Sharingan Boy");
    */


    Stack <pair<int, char>> st;

    st.push(make_pair(1,'a'));
    st.push(make_pair(2,'b'));
    st.push(make_pair(3,'c'));


    while(!st.empty())
    {
        pair<int,char> chk;
        chk = st.pop();
        cout<<chk.first<<" | "<<chk.second<<endl;
        //cout << st.pop() <<endl;
    }/*
    */

    cout<< st.size()<<endl;
    if(st.empty())
    {
        //cout<<st.Top()<<endl;
                pair<int,char> chk;
        chk = st.pop();
        cout<<chk.first<<" | "<<chk.second<<endl;
    }

    return 0;
}

