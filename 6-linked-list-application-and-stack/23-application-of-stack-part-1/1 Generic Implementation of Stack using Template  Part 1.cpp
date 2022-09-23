#include<bits/stdc++.h>
using namespace std;

template<typename T>T myMax(T a, T b)
{
    return (a>b)?a:b;
}

int main()
{
    //functionName <DataType> (Parameter)
    cout<<myMax<int>(3,7)<<endl;
    cout<<myMax<float>(3.4,7.1)<<endl;
    cout<<myMax<char>('a','f')<<endl;

}
