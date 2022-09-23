#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,x;
    int l[101];
    int r[101];
    int count[101];
    //int x;

    cin>>n;
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",l+i,r+i);
        if(!l[i])
        {
             count[++x]=i;
        }
    }

    for(int i=1,j;i<x;++i)
    {
        for(j=count[i];r[j]!=0;j=r[j]);

        r[j]=count[i+1];
        l[count[i+1]]=j;
    }

    cout<<endl<<endl;
    for(int i=1;i<=n;++i)
   	 {cout<<l[i]<<" ";
   	 cout<<r[i];
   	 cout<<endl;}
    return 0;
}

