#include<bits/stdc++.h>
using namespace std;

class Example
{
public:
    int add(int x,int y)
    {
        return x+y;
    }
    double add(double x,double y)
    {
        return x+y;
    }
    void add(char a)
    {
        cout<<"Hi "<<a<<endl;
    }
};


int main()
{
    Example ex;
    ex.add('s');
    //cout<<ex.add(1,2)<<endl;
    return 0;
}




