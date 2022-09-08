#include<bits/stdc++.h>
#define mx 100005
using namespace std;
int arr[mx];
int tree[mx*3];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    //cin>>tree[node];
    int left =node*2;
    int right = node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]= tree[left]+tree[right];
}

int query(int node,int b,int e,int i, int j)
{
    if(b>j || e<i)
    {
        return 0;
    }
    if(b>=i && e<=j)
    {
        //tree[node] = tree[i];
        return tree[node];
    }
    int left =node*2;
    int right = node*2+1;
    int mid=(b+e)/2;
    int q1=query(left,b,mid,i,j);
    int q2=query(right,mid+1,e,i,j);
    return q1+q2;
}
void update(int node,int b,int e,int i,int newvalue)
{
    if(i>e || i<b)
        return;
    if(b>=i && e<=i)
    {
        tree[node]=newvalue;
        return;
    }
    int left =node*2;
    int right = node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]= tree[left]+tree[right];
}
int main()
{
    int t,n,q,v,x,y,z;
    cin>>t;

    for(int i=1; i<=t; i++)
    {
        cout<<"Case "<<i<<":"<<endl;
        cin>>n>>q;

        for(int j=0; j<n; j++)
        {
            cin>>arr[j];
        }

        init(1,0,n-1);

        for(int k=0; k<q; k++)
        {
            cin>>x;

            if(x==1)
            {
                cin>>y;
                cout<<arr[y]<<endl;
                arr[y]=0;
                update(1,0,n-1,y,0);
            }

            else if(x==2)
            {
                cin>>y>>z;
                arr[y]+=z;
                update(1,0,n-1,y,arr[y]);

            }

            else
            {
                cin>>y>>z;
                int ans=query(1,0,n-1,y,z);
                cout<<ans<<endl;
            }
        }
    }

    return 0;
}
