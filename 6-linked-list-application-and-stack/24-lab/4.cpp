#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x,y,i,j;
	int max=0;
	cin>>x>>y;

	int array[x][y];

	for(i=0; i<x; i++)
	{
    	for(j=0; j<y; j++)
    	{
            cin>>array[i][j];
    	}
	}

	for(i=0;i<x;i++)
	{
	    for(j=0;j<y;j++)
        {
            if(array[i][j]>max)
            {
                max=array[i][j];
            }
        }
	}
	int freq[max+1]={0};

  	for(i=0;i<x;i++)
	{
	    for(int j=0;j<y;j++)
        {
            if(freq[array[i][j]]>=1)
            {
                array[i][j] = -1;
            }

            else
            {
                freq[array[i][j]]++;
            }

        }
	}

    for(i=0;i<x;i++)
	{
    	for(j=0;j<y;j++)
    	{
            cout<<array[i][j]<<" ";
    	}
    	cout<<endl;
	}

	return 0;
}
