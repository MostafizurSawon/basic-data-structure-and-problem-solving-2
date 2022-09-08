#include<bits/stdc++.h>
using namespace std;

class Bank
{
    public:
        string name;
        string address;
        int age;
        int ac_no;
    private:
        string password;
    protected:
        int balance;
    public:
        Bank(string name,string address,int age,string password)
        {
            this->name = name;
            this->address = address;
            this->age = age;
            this->password = password;
            this->balance = 0;
            this->ac_no = rand()%1000000000;
            cout<<"Your Account Number is: "<<this->ac_no<<endl;
            cout<<"Your name is: "<<this->name<<endl;
            cout<<"Your address is: "<<this->address<<endl;
            cout<<"Your age is: "<<this->age<<endl;
            cout<<"Your current password is: "<<this->password<<endl;
            cout<<"Your Current Balance is: "<<this->balance<<endl;
        }

        int mainBalance(string p)
        {
            if(this->password == p)
            {
                return this->balance;
            }
            else
            {
                return -1;
            }
        }

        void depositMoney(string p,int amount)
        {
            if(this->password == p)
            {
                this->balance += amount;
                cout<<"Balance added successfully"<<endl;
            }
            else
            {
                cout<<"password didn't match"<<endl;
            }
        }

        void withdrawMoney(string p, int amount)
        {
            if(amount>balance)
            {
                cout<<"Exceeds current balance!!"<<endl;
                return;
            }
            if(amount == balance)
            {
                cout<<"Khatam!!!\nTata bye bye!!!"<<endl;
            }
            if(this->password == p)
            {
                this->balance -= amount;
                cout<<"Balance withdrawn Successfully"<<endl;
            }
            else
            {
                cout<<"Password didn't match!!"<<endl;
            }
        }
        friend class FastCash;
};

class FastCash
{
protected:
    int balance;
public:
    FastCash()
    {
        this->balance=0;
    }
    void addMoneyFromBank(Bank *myAccount,string p,int amount)
    {
        if(amount < 0)
        {
            cout<<"Invalid ammount"<<endl;
            return;
        }
        if(myAccount->balance < amount)
        {
            cout<<"Exceeds current balance"<<endl;
            return;
        }
        if(myAccount->password == p)
        {
            this->balance += amount;
            myAccount->balance -= amount;
        }
        else
        {
            cout<<"Password didn't match"<<endl;
        }
    }
    int mainBalance()
    {
        return balance;
    }
};

Bank* newAccount()
{
    string name,address,password;
    int age;
    cout<<"Create Your Bank Account: "<<endl;
    cout<<endl;
    cout<<"Your Name: ";
    cin>>name;
    cout<<"Your Address: ";
    cin>>address;
    cout<<"Your Age: ";
    cin>>age;
    cout<<"Your Password: ";
    cin>>password;

    Bank *myAccount = new Bank(name,address,age,password);
    return myAccount;
}

void depositMoney(Bank *myAccount)
{
    string password;
    int money;
    cout<<endl;
    cout<<"Add Money: ";
    cout<<endl;
    cout<<"Enter your password: ";
    cin>>password;
    cout<<"Enter amount: ";
    cin>>money;
    myAccount->depositMoney(password,money);
    cout<<"Your Current Balance is: "<<myAccount->mainBalance(password)<<endl;
}

void withdrawMoney(Bank *myAccount)
{
    string password;
    int money;
    cout<<endl;
    cout<<"Withdraw Money: ";
    cout<<endl;
    cout<<"Enter your password: ";
    cin>>password;
    cout<<"Enter amount: ";
    cin>>money;
    myAccount->withdrawMoney(password,money);
    cout<<"Your Current Balance is: "<<myAccount->mainBalance(password)<<endl;
}

void addMoneyFromBank(FastCash *fastCash,Bank *myAccount)
{
    string password;
    int money;
    cout<<endl;
    cout<<"Add Money to FastCash: ";
    cout<<endl;
    cout<<"Enter your password: ";
    cin>>password;
    cout<<"Enter amount: ";
    cin>>money;
    fastCash->addMoneyFromBank(myAccount,password,money);
    cout<<"Your bank balance is "<<myAccount->mainBalance(password)<<endl;
    cout<<"Your FastCash Balance is: "<<fastCash->mainBalance()<<endl;
}


int main()
{
    Bank *myAccount = newAccount();
    FastCash *fastCash = new FastCash;


Flag:
    cout<<"Select Option: "<<endl;
    cout<<"1. Deposit Money to Bank"<<endl;
    cout<<"2. Withdraw Money from Bank"<<endl;
    cout<<"3. Add Money to FastCash from Bank"<<endl;

    int option;
    cin>>option;

    if(option == 1)
    {
        depositMoney(myAccount);
    }
    else if(option == 2)
    {
        withdrawMoney(myAccount);
    }
    else if(option == 3)
    {
        addMoneyFromBank(fastCash,myAccount);
    }
    else
    {
        cout<<"Invalid Option!!"<<endl;
    }
    goto Flag;

    return 0;
}

//module3 lab01 dynamicAllocation
