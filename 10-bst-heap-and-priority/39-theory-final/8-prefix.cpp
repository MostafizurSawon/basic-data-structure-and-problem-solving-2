#include<bits/stdc++.h>
#include"stack8.h"

using namespace std;

int precCalc(char a)
{
    if(a == '^')
    {
        return 3;
    }
    else if(a == '*' || a == '/')
    {
        return 2;
    }
    else if(a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPrefix(string chk)
{
    reverse(chk.begin(), chk.end());

    Stack<char> st;

    string result = "";

    for(int i = 0; i < chk.size(); i++)
    {
        if(chk[i] >= '0' && chk[i] <= '9')
        {
            result += chk[i];
        }
        else if(chk[i] == ')')
        {
            st.push(chk[i]);
        }
        else if(chk[i] == '(')
        {
            while(!st.isEmpty() && st.getTop()!= ')')
            {
                result += st.pop();
            }

            if(!st.isEmpty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.isEmpty() && precCalc(st.getTop()) > precCalc(chk[i]))
            {
                result += st.pop();
            }
            st.push(chk[i]);
        }
    }

    while(!st.isEmpty())
    {
        result += st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}


int prefixEv(string chk)
{
    Stack<int> st;

    for(int i = chk.length()-1; i>=0; i--)
    {
        if(chk[i] >= '0' && chk[i] <= '9')
        {
            st.push(chk[i]-'0');
        }
        else
        {
            int x = st.pop();
            int y = st.pop();

            switch(chk[i])
            {
            case '+':
                st.push(x+y);
                break;
            case '-':
                st.push(x-y);
                break;
            case '*':
                st.push(x*y);
                break;
            case '/':
                st.push(x/y);
                break;
            case '^':
                st.push(pow(x,y));
                break;
            default:
                break;
            }
        }
    }
    return st.getTop();
}


int main()
{
    string st;
    cout<<"Enter your desired string: ";

    cin>>st;
    string result;

    result = infixToPrefix(st);

    cout<<"Prefix : "<<result<<endl;
    cout<<"Result : "<<prefixEv(result)<<endl;

    return 0;
}
