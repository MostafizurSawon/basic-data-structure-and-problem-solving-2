#include<bits/stdc++.h>
using namespace std;

void print(int *x)
{
    *x = 50;
}

int main()
{
    int a = 10;
    int *ptr = &a;
    print(ptr);
    cout<<a<<endl;

    return 0;
}
