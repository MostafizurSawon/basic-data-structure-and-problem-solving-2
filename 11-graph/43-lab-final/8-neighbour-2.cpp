#include <bits/stdc++.h>

using namespace std;

class Neighbour
{
    int V;
    list<int>*adj;

public:
    Neighbour(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        //adj[u].push_front(u);
        adj[u].push_back(v);
    }

    void bfs(int src)
    {
        int ans = 0;

        vector<bool>visited(V, false);
        queue<int>q;

        visited[src] = true;
        q.push(src);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            //cout<<u;

            for (auto element : adj[u])
            {
                int a = element;
                //cout<<a;

                if (visited[a] != true)
                {
                    visited[a] = true;
                    q.push(a);

                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
};

int main()
{
    int N,E;
    cin>>N>>E;

    Neighbour gr(N);

    for (int i=0; i<E; i++)
    {
        int x, y;
        cin >>x>>y;

        gr.addEdge(x, y);
    }

    int K;
    cin>>K;

    gr.bfs(K);

    return 0;
}
