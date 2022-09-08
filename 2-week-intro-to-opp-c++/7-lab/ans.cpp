#include<bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    char section;
    int roll;
protected:
    int english_marks;
private:
    string password;
public:
    void set_password(string pass)
    {
        password=pass;
    }
    void set_marks(int marks)
    {
        english_marks=marks;
    }
    int get_marks()
    {
        return english_marks;
    }
    void update_marks(string pass, int marks)
    {
        if(pass==password)
        {
            english_marks=marks;
        }
        else
        {
            cout<<"Password didn't match!"<<endl;
        }
    }

};
int main()
{
    int n;
    cin>>n;
    Student st[n];
    for(int i=0;i<n;i++)
    {
        string name,password;
        char section;
        int roll,marks;
        cin>>name>>section>>roll>>marks>>password;
        st[i].name=name;
        st[i].section=section;
        st[i].roll=roll;
        st[i].set_marks(marks);
        st[i].set_password(password);
    }
    int roll,marks;
    string password;
    cin>>roll>>marks>>password;
    bool found=false;
    for(int i=0;i<n;i++)
    {
        if(st[i].roll == roll )
        {
            found=true;
            st[i].update_marks(password,marks);
        }
    }
    if(!found)
    {
        cout<<"Student not found!"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cout<<st[i].name<<" "<<st[i].section<<" "<<st[i].roll<<" "<<st[i].get_marks()<<endl;
    }
    return 0;
}

/*

1.Make an array of Student class of size N. Template is given below:
Class Student
{
    string name;
    char section;
    int roll;
    int english_marks;
    string password;
}

2.Make name, section and roll as public so that these can be accessed outside.

3.Make english_marks protected so that this can’t be accessed outside except the derived class.

4.Make the password private so that this can’t be accessed outside.

5.Make a set_marks() function inside Student that will set english_marks of Student class;

6.Make a set_password() function inside Student that will set password to Student class.

7.Make a get_maks() function inside Student that will return english_marks of the Student.

8.Take name, section, roll, marks, and password as input for all Student class from the user and set them to the array of Student.

9.Make a function named update_marks() in the Student class which will take a string password and int marks as parameters and will check if the password matches with that student, and set the marks to english_marks of that Student. If the password doesn’t match, show an error.

10.Take roll, marks and password input from the user and find the Student that matches with the roll. If the Student is not found, show an error.

11.If the Student is found, call update_marks() function to update the english_marks of that Student.

12.Print all information except the password of all Student.

*/
