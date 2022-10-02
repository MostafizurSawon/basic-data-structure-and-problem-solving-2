#include<bits/stdc++.h>
using namespace std;

class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int quantity[12];
    double total_tax;

    void getter();
    void setter();

    Restaurant()
    {
       total_tax=0;
    }
};


void Restaurant::getter()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
      cin>>food_item_codes[i];
      //ignore
      cin.ignore();

      getline(cin,food_item_names[i]);

      cin>>food_item_prices[i];
    }
}

void Restaurant::setter()
{
    cout<<endl;
    cout<<"\t\t\t\t"<<"MAKE BILL"<<endl;
    cout<<"\t\t\t"<<"_________________________"<<endl;
    cout<<endl;

    cout<<"Item Code"<<"\t\t"<<"Item Name"<<"\t\t"<<"Item Price"<<endl;
    cout<<endl;

    for(int i=0; i<12; i++)
    {
      cout<<"  "<<food_item_codes[i]<<"\t\t"<<food_item_names[i] <<"\t\t"<<"   "<<food_item_prices[i]<<endl;
    }
}

void table(Restaurant item_management,Restaurant food)
{
int tableNo,items,code,quantity,k,sum = 0;
cout<<endl;
cout<<endl;

cout<<"Enter Table : ";
cin>>tableNo;

cout<<"Enter Number of items : ";
cin>>items;

//cin.ignore();

for(int i=0; i<items; i++)
{
    billMenu:
        cout<<"Enter Item "<<i+1<<" Code : ";
        cin>>code;
        bool stock = false;

    for(int j=0; j<12; j++)
    {
        if(code == item_management.food_item_codes[j])
        {
            stock = true;
            cout<<"Enter Item "<<i+1<<" Quantity : ";
            cin>>quantity;

            food.food_item_codes[k]=item_management.food_item_codes[j];
            //food.food_item_codes[k]=item_management.food_item_codes[j+1];
            food.food_item_prices[k]=item_management.food_item_prices[j];
            food.food_item_names[k]=item_management.food_item_names[j];
            food.quantity[k]=quantity;
            k++;
        }
    }

    if(!stock)
    {
        cout<<"Invalid code!\nPlease write again";
        cout<<endl;

        goto billMenu;
    }

}

cout<<endl;

cout<<"\t\t\t\t"<<"BILL SUMMARY"<<endl;
cout<<"\t\t\t"<<"___________________________"<<endl;

cout<<"Table No : "<<tableNo<<endl;
cout<<endl;

cout<<"Item Code"<<"\t"<<"Item Name"<<"\t\t\t"<<"Item Price"<<"\t"<<"Item Quantity"<<"\t\t"<<"Total Price"<<endl;

int total;

for(int i=0;i<k;i++)
{
    sum += food.food_item_prices[i]*food.quantity[i];
    food.total_tax = sum*5/100;
    total = sum + food.total_tax;

    cout<<food.food_item_codes[i]<<"\t\t"<<food.food_item_names[i] <<"\t\t"<<"    "<<food.food_item_prices[i]<<"\t\t"<<"     "<<food.quantity[i]<<"\t\t\t"<<"    "<<food.food_item_prices[i]*food.quantity[i]<<endl;
}

cout<<"TAX"<<"\t\t\t\t\t\t\t\t\t\t\t"<<"    "<<food.total_tax<<endl;
cout<<"___________________________________________________________________________________________________________"<<endl;
cout<<"Net Total\t\t\t\t\t\t\t\t\t\t"<<"   "<<total <<" Taka"<<endl;
}

int main()
{
    cout<<"Welcome to SawOn's restuarent."<<endl;
    cout<<"Number of foods: ";

    Restaurant item_management;
    Restaurant food;

    item_management.getter();

    //item_management.setter();

    while(true)
    {
        item_management.setter();
        table(item_management,food);
    }

    return 0;
}
