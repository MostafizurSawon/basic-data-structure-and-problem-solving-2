#include<bits/stdc++.h>
using namespace std;

class Parent
{
private:
    int taka;
public:
    Parent(int tk)
    {
        taka=tk;
    }
    friend class AbburBondhu;
};

class AbburBondhu
{
public:
    void tellSecret(Parent *ptr)
    {
        cout<<ptr->taka<<endl;
    }
};


int main()
{
    Parent pt(1500);
    AbburBondhu bondhu;
    bondhu.tellSecret(&pt);
    //cout<<ex.add(1,2)<<endl;
    return 0;
}





