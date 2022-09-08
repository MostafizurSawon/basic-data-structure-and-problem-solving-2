#include<bits/stdc++.h>
using namespace std;

int main(){
    string st;
	cin >> st;

	int a,b;

	for (int i=0; i<st.size(); i++) {
		if (st[i]=='A')
        {
			a = i;
			break;
		}
	}

	for(int j=st.size()-1; j>0; j--)
	{
		if (st[j] == 'Z')
        {
			b = j;
			break;
		}
	}

	int ans = b - a + 1;

	cout<<ans;

	return 0;

/*
	string S;
	cin >> S;
	int na=find(S.begin(),S.end(),'A')-S.begin();
	int nz=find(S.rbegin(),S.rend(),'Z')-S.rbegin();
	cout << S.size()-na-nz << endl;

    return 0;
*/
}
