#include<bits/stdc++.h>
#define MAX 100005
#define max 100000000

using namespace std;

int A[MAX<<2],input[MAX];

void build(int lf,int rt,int idx)
{
       if(lf==rt){
                A[idx] = input[lf];
                return ;
        }
        int mid = (lf + rt) /2;

        build(lf,mid,2*idx);
        build(mid+1,rt,2*idx + 1);
        A[idx] = min(A[2*idx], A[2*idx+1]);
}

int query(int lf,int rt,int indx,int x,int y)
{
   if(lf>=x && rt<=y) return A[indx];

   int mid=(lf+rt)/2;
   int ans=max;
   if(x<=mid)
   {
       ans=min(ans,query(lf,mid,2*indx,x,y));
   }

   if(y>mid)
   {
       ans=min(ans,query(mid+1,rt,2*indx+1,x,y));
   }

   return ans;

}
int main()
{
 int T;
 cin>>T;

 for(int i=1;i<=T;i++)
 {
      int N,Q,I,J;
      cin>>N>>Q;
      for(int i=1;i<=N;i++)
      {
          cin>>input[i];
      }

      build(1,N,1);

      cout<<"Case "<<i<<":\n";

      while(Q--)
      {
       cin>>I>>J;
       cout<<query(1,N,1,I,J);
      }

 }

 return 0;
}
