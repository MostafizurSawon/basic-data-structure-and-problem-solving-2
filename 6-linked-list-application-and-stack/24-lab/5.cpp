#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,ans = 0,i,j;
	cin>>n;

	int array[n][n];

	for(i=0; i<n; i++)
    {
    	for(j=0; j<n; j++)
        {
        	cin>>array[i][j];
    	}
	}

    for(i=0; i<n; i++)
    {
        ans += array[i][n/2];
    }

    for(i=0; i<n; i++)
    {
        ans += array[n/2][i];
    }

    for(i=0; i<n/2; i++)
    {
        ans += array[i][n-1];
    }

    for(i=(n/2)+1; i<n; i++)
    {
        ans += array[0][i];
    }

    for(i=0; i<n/2; i++)
    {
        ans += array[i][0];
    }

    for(i=(n/2)+1; i<n; i++)
    {
        ans += array[n-1][i];
    }

    ans -= array[n/2][n/2];

    cout<<endl<<ans<<endl;

    return 0;
}
