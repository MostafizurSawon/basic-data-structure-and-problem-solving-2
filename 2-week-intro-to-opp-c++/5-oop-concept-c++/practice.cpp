#include<bits/stdc++.h>
using namespace std;

class Parent
{
    public:
        int x;
    private:
        int y;
    public:
        Parent(int a)
        {
            y=a;
        }
    friend class Der;
};

class Der
{
public:
    void tellNow(Parent *pntr)
    {
        cout<<"Protected friend value: "<<pntr->y<<endl;
    }
};


int main()
{
    Parent pt(10);
    Der d;
    d.tellNow(&pt);

    return 0;
}

/*
class Student
{
public:
    char nam[100];
    int roll;
};

int main()
{
    Student Sawon;
    strcpy(Sawon.nam,"Mostafizur");
    Sawon.roll=17;
    cout<<Sawon.nam<<" "<<Sawon.roll<<endl;

    return 0;
}
*/

/*
class Geto
{
    public:
    int x;
    int y;
    int z;
    Geto(int a,int b,int c)
    {
        x=a;
        y=b;
        z=c;
    }
};


int main()
{
    Geto Today(5,10,15);
    cout<<Today.x<<" "<<Today.y<<" "<<Today.z<<endl;

    return 0;
}
*/

/*
class Geto
{
private:
    int x;
    int pass;
public:
    Geto(int p)
    {
        pass=p;
    }
    void setter(int a,int p)
    {
        if(pass==p)
        {
            x=a;
        }
        else
        {
            cout<<"Password didn't match"<<endl;
        }
    }
    int getter(int p)
    {
        if(pass==p)
        {
            return x;
        }
        else
        {
            return -1;
        }
    }

};


int main()
{
    Geto Today(1106);
    Today.setter(5000,1106);
    cout<<Today.getter(1106)<<endl;

    return 0;
}
*/
