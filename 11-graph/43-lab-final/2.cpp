#include <bits/stdc++.h>
using namespace std;

class Graph
{
     int val;
     list<int>*adj;

public:
     Graph(int val)
     {
         this->val = val;
         adj = new list<int>[val];
     }

    void addEdge(int u,int val)
    {
        adj[u].push_back(val);

        adj[val].push_back(u);
    }

    void bfs(int src,int l)
    {
        vector<bool>visited(val,false);  //vector all sob size = false
        queue<int>q;

        int level=0;

        visited[src]=true;

        q.push(src);
        q.push(-1);

        while(!q.empty())
        {
            int x = q.front();

            q.pop();

            if(x!=-1)
            {
                if(l==level)
                {
                    cout<<x<<" ";
                }
                else
                {
                    for(auto i:adj[x])
                    {
                         if(visited[i]!=true)
                         {
                            visited[i]=true;
                            q.push(i);
                         }
                    }
                }
            }

            else
            {
                if(!q.empty())
                {
                    q.push(-1);
                    level++;
                }
            }
        }
    }
};


int main()
{
    int n,e;
    cin>>n>>e;

    Graph gr(n);

    for(int i=0; i<e; i++)
    {
       int x,y;
       cin>>x>>y;

       gr.addEdge(x,y);
    }

    int l;
    cin>>l;

    gr.bfs(0,l);

    return 0;
}
