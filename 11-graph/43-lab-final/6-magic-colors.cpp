#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        stack<char> m;
        queue<char> p;
        stack<char> q;
        queue<char> r;
        stack<char> s;

        int x;
        cin>>x;

        char ch;
        for(int i=0; i<x; i++)
        {
            cin>>ch;
            p.push(ch); //push color
        }

        while(!p.empty())
        {
            char a = p.front(); //keep in a variable
            p.pop();    //delete

            char b;

            if (q.empty())
            {
                q.push(a);
                b = q.top();
            }

            else
            {
                if (a == 'R' && b == 'G' || a == 'G' && b == 'R')
                {
                    q.pop();
                    r.push('Y');
                }

                else if(a == 'R' && b == 'B' || a == 'B' && b == 'R')
                {
                    q.pop();
                    r.push('P');
                }

                else if(a == 'B' && b == 'G' || a == 'G' && b == 'B')
                {
                    q.pop();
                    r.push('C');
                }

                else if(a == q.top())
                {
                    q.pop();
                }
            }
        }

        while(!r.empty())
        {
            char a = r.front();
            r.pop();

            char b;
            if(m.empty())
            {
                m.push(a);
                b = m.top();
            }
            else
            {
                if (a == b)
                {
                    m.pop();
                    if (!m.empty())
                    {
                        b = m.top();
                    }
                }
                else if (a != b)
                {
                    m.push(a);
                    b = m.top();
                }
            }
        }

        while(!m.empty())
        {
            char a = m.top();
            m.pop();
            s.push(a);
        }

        while(!s.empty())
        {
            char a = s.top();
            s.pop();
            cout << a;
        }

        while(!q.empty())
        {
            char a = q.top();
            q.pop();
            cout << a;
        }
        cout << endl;
    }

    return 0;
}
