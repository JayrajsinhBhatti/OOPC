#include<iostream>
#include<iomanip>
using namespace std;

class Inventory {

    int productCount = 0;
    int product[30];
    int quantity=0;
    int prodCount=0;

    public:

    //Add product
    void add(int id, string name, int rate) {
        if (productCount>=30)
        {
            cout<<"List is full!"<<endl;
            return;
        }
        cout<<"Product added successfully!"<<endl;
        prodCount++;
    }

    //Search Product
    int cound=0;
    bool search(int id) {
        for(int i=0;i<prodCount;i++)
        {
            if (product[i]==id)
            {
                return true;
            }
        return false;
        }
    }

    //Update quantity
    void Update(int id) {
        if (search(id))
        {
            quantity++;
        }
    }

    //Total Value
    double Totalvalue = 0;
    void TotalValue(int price) {
        for(int i=0;i<productCount;i++)
        {
            Totalvalue += price * quantity; 
        }
    }

    //Print Bill
    void PrintBill(int id, string name, int price) {
        for(int i=0;i<productCount;i++)
        {
            cout<<id<<setw(10)<<name<<setw(17)<<quantity<<setw(-2)<<price<<setw(-4)<<Totalvalue<<endl;
        }

    }
};

int main() 
{
    int pid, quantity, price;
    string name;
    Inventory i;
    int choice;

    while (true)
    {
        cout << "\n--- Inventory Management System ---\n";
        cout << "1. Add Product\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:     //add
            cout<<"Enter id: ";
            cin>>pid;
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter price: ";
            cin>>price;

            i.add(pid, name, price);    

            i.search(pid);
            i.Update(pid);
            i.TotalValue(price);
            cout<<"Product added successfully!"<<endl;
            break;
        case 0:
            i.PrintBill(pid, name, price);
            cout << "Exiting...\n";
            return 0;
            break;
        
        default:
            cout << "Invalid choice! Try again.\n";
            break;
        }
        // if (choice == 1) i.add();
        // else if (choice == 2) i.Update();
        // else if (choice == 3) i.TotalValue();
        // else if (choice == 4) i.PrintBill();
        // else if (choice == 5) {
            
        //     break;
        // } else {
            
        // }
    }
    
}