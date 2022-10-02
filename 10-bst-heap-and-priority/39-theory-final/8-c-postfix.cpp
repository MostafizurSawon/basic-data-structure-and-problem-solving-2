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


string infixToPostfix(string chk)
{
    Stack<char> a;
    string result = "";

    for(int i = 0; i < chk.size(); i++)
    {
        cout<<"Notation : "<<result<<endl;
        if(chk[i]>= '0' && chk[i]<= '9')
        {
            result+= chk[i];
        }
        else if(chk[i] == '(')
        {
            a.push(chk[i]);
        }
        else if(chk[i] == ')')
        {
            while(!a.isEmpty() && a.getTop() != '(')
            {
                result += a.pop();
            }
            if(!a.isEmpty()) a.pop();
        }
        else
        {
            while(!a.isEmpty() && precCalc(a.getTop()) > precCalc(chk[i]))
            {
                result +=a.pop();
            }
            a.push(chk[i]);
        }
    }
    while(!a.isEmpty()){
        result += a.pop();
    }

    return result;
}


int postfixEvaluation(string chk){
    Stack<int> a;

    for(int i = 0; i < chk.size(); i++)
    {
        if(!a.isEmpty())
        {
            cout<<"Stack current status: ";
            a.iterateStack();
        }

        if(chk[i]>= '0' && chk[i] <= '9'){
            a.push(chk[i] - '0');
        }
        else
        {
            int x = a.pop();
            int y = a.pop();
            switch(chk[i]){
            case '+':
                a.push(y+x);
                break;
            case '-':
                a.push(y-x);
                break;
            case '*':
                a.push(y*x);
                break;
            case '/':
                a.push(y/x);
                break;
            case '^':
                a.push(pow(y, x));
                break;
            default:
                break;
            }
        }
    }
    return a.getTop();
}

int main()
{
    string st;
    cout<<"Enter your desired string: ";
    cin>>st;

    string result;
    result = infixToPostfix(st);

    cout<<"Postfix : "<<result<<endl;
    cout<<"Result  : "<<endl<<postfixEvaluation(result)<<endl;

    return 0;
}
