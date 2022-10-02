#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    while(n--){
        int a,b;
        cin>>a>>b;

        int array[a],sum=0;

        for(int i=0;i<a;i++)
        {
            cin>>array[i];
            sum += array[i]*2;
        }

        if(b-sum>=0){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}
