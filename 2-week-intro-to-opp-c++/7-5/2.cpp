#include<bits/stdc++.h>
using namespace std;

class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int quantity[100];
    int total_tax;
};

int main()
{
    int n;
    cout<<"Number of foods : "<<endl;
    cin>>n;

    Restaurant restaurant[n];

    for(int i=0; i<n; i++)
    {
        cin>>restaurant->food_item_codes[i];
        cin.ignore();
        getline(cin,restaurant->food_item_names[i]);
        cin>>restaurant->food_item_prices[i];
    }

    cout<<endl;
    cout<<"\t\t\t\t"<<"MAKE BILL"<<endl;
    cout<<"\t\t\t"<<"_________________________"<<endl;
    cout<<endl;

    cout<<"Item Code"<<"\t\t"<<"Item Name"<<"\t\t"<<"   "<<"Item Price"<<endl;
    cout<<endl;

    for(int i=0;i<n;i++)
    {
      cout<<restaurant->food_item_codes[i]<<"\t\t\t"<<restaurant->food_item_names[i]<<"\t\t"<<restaurant->food_item_prices[i]<<endl;
    }

    cout<<endl;

    cout<<"\t\t\t\t"<<"BILL SUMMARY"<<endl;
    cout<<"\t\t\t"<<"___________________________"<<endl;

    int tableNo;
    cout<<"Enter Table no : ";
    cin>>tableNo;

    int numberOfItems;
    cout<<"Enter Number of Items : ";
    cin>>numberOfItems;

    for(int i=0; i<numberOfItems ;i++)
    {
     cout<<"Enter item "<<i+1<<" code:";
     cin>>restaurant->food_item_codes[i];
     cout<<"Enter item "<<i+1<<" quantity:";
     cin>>restaurant-> quantity[i];
    }
    cout<<endl;
    cout<<endl;

    cout<<"Item Code"<<"\t\t"<<"Item Name"<<"\t\t"<<"Item Price"<<"\t\t"<<"Item Quantity"<<"\t\t"<<"Total Price"<<endl;

    for(int i=0; i<numberOfItems; i++)
    {
      cout<<restaurant->food_item_codes[i]<<"\t\t\t"<<restaurant->food_item_names[i]<<"\t\t"<<restaurant->food_item_prices[i]<<"\t\t\t"<<restaurant->quantity[i]<<"\t\t"<<restaurant->food_item_prices[i]*restaurant->quantity[i]<<endl;

    }
    cout<<"_______________________________________________________________________________________________________"<<endl;
     cout<<"NET TOTAL";
    int sum=0;
    for(int i=0;i<numberOfItems;i++)
    {
      sum+=restaurant->food_item_prices[i]*restaurant->quantity[i];
    }
    cout<<"\t\t\t\t\t\t\t\t\t\t"<<sum<<endl;
}
