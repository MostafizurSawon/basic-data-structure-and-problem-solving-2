#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
public:
    string account_holder;
    string address;
    int age;
    int account_number;
protected:
    int balance;
private:
    string password;
public:
    BankAccount(string account_holder,string address,int age,string password)
    {
        this->account_holder=account_holder;
        this->address=address;
        this->age=age;
        this->password=password;
        this->account_number=rand()%1000000000;
        this->balance=0;
        cout<<"Your account no is "<<this->account_number<<endl;
    }
    int show_balance(string password)
    {
        if(this->password == password)
        {
            return this->balance;
        }
        else
        {
            return -1;
        }
    }
    void add_money(string password, int amount)
    {
        if(this->password == password)
        {
            this->balance += amount;
            cout<<"Add Money Successfully"<<endl;
        }
        else
        {
            cout<<"Password didn't match"<<endl;
        }
    }

    void withdraw_money(string password, int amount)
    {
        if(this->password == password)
        {
            this->balance -= amount;
            cout<<"Withdraw Money Successfully"<<endl;
        }
        else
        {
            cout<<"Password didn't match"<<endl;
        }
    }
};

BankAccount* create_account()
{
    string account_holder,password,address;
    int age;
    cout<<"Create Your Account"<<endl;
    cin>>account_holder>>address>>age>>password;
    BankAccount *myAccount = new BankAccount(account_holder,address,age,password);
    return myAccount;
}

void add_money(BankAccount *myAccount)
{
string password;
int amount;
cout<<"ADD MONEY"<<endl;
cin>>password>>amount;
myAccount->add_money(password,amount);
cout<<"Your bank balance is "<<myAccount->show_balance("abc")<<endl;
}

void withdraw_money(BankAccount *myAccount)
{
string password;
int amount;
cout<<"Withdraw MONEY"<<endl;
cin>>password>>amount;
myAccount->withdraw_money(password,amount);
cout<<"Your bank balance is "<<myAccount->show_balance("abc")<<endl;
}

int main()
{
    BankAccount *myAccount = create_account();
    add_money(myAccount);
    withdraw_money(myAccount);
    return 0;
}


