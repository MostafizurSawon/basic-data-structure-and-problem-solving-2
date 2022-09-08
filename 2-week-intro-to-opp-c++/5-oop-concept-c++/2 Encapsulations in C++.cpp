#include<bits/stdc++.h>
using namespace std;

class Student
{
    public: //Access modifier / Specifier
    int x;

    private:
    int y;

    protected:
    int z;

};

int main()
{
    Student rahim;
    rahim.x=10;
    //rahim.y=20;
    //rahim.z=30;

    cout<<rahim.x<<endl;
    return 0;
}

