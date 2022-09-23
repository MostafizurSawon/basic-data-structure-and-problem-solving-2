#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,i;
    cin>>n;

    while(n--)
    {
        int a,query;
        cin>>a;

        int happy[a];
        int upset[a];

        for(i=0;i<a;i++)
        {
            cin>>happy[i];
        }

        for(i=0;i<a;i++)
        {
            cin>>upset[i];
        }

       cin>>query;

        while(query--)
        {
            int queryN, count1 = 0, count2 = 0;
            cin>>queryN;

            for(int i=0;i<=queryN;i++)
            {
                count1 += happy[i];
                count2 += upset[i];
            }

            if(count2>count1)
            {
                cout<<"0"<<endl;
            }
            else
            {
                cout<<"1"<<endl;
            }
        }

        cout<<endl;
    }

    return 0;
}
