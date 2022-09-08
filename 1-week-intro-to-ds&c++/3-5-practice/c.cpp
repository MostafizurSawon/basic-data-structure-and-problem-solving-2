#include<bits/stdc++.h>
using namespace std;

int main(){
    char s[1000000];
    cin>>s;

    int len=strlen(s);
    int freq[26]={0};

    for(int i=0;i<len;i++){
        int ans=s[i]-'a';
        freq[ans]++;
    }

    for(int i=0;i<26;i++){
        if(freq[i]==0){
            char val=i+'a';
            cout<<val<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
    return 0;
}
