#include<iostream>
#include "structs.h"
using namespace std;
int main(){
    Inventory inv;
    Items item;
    List list;
    Store store;
    Order order;
    cout << "=== Welcome to the \"Great Stand Alone\" Store ====\n";
    cout << "Let's know who are you ? (Admin (1) / customer(0) )\n";
    int choice;
    cin >> choice;
    while(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid input! Enter integer value: ";
        cin >> choice;
    }
    while(choice != 1 && choice != 0){
        cout << "Invlaid input! Enter 1 or 0: ";
        cin >> choice;
    }

    if(choice==1){
        
        cout << "Please prove your identity!\nEnter 6 digits PIN: ";
        int pin;
        cin>>pin;
        if (pin<123456 || pin>234567)
        {
            cout << "Invalid pin! We can't let you enter the system.";
            return 0;
        }

        else{
            while(true){
            cout << "Please choose what operations you want to perform ?\n"
                 << "1. Display inventory.\n"
                 << "2. Display items in the store.\n"
                 << "3. Add item.\n"
                 << "4. Remove item.\n"
                 << "5. Change items name.\n"
                 << "6. Change items price.\n"
                 << "7. Add items quantity.\n"
                 <<"8. Display orders history.\n"
                 <<"9. Calculate total revenue.\n"
                 <<"10. Print orders in sorted order.\n"
                 <<"11. Add order in the history.\n"
                 <<"12. Remove order in the history.\n"
                 << "13. Exit.\n";
            int choice;
            cin >> choice;
            while (cin.fail()){
                cout << "Invalid input! Enter integer value 1-8 : ";
                cin >> choice;
            }
            while(choice<1 || choice>8){
                cout << "Enter choice b/w 1-8 : ";
                cin >> choice;
            }
            
            switch (choice)
            {
            case 1:
                inv.printInventory();
                break;
            case 2:
                item.printItemDetails();
                break;
            case 3:
                inv.addItem();
                break;
            case 4:
                inv.removeItem();
                break;
            case 5:
                item.changeItemName();
                break;
            case 6:
                item.changeItemPrice();
                break;
            case 7:
                item.addQuantity();
                break;
            case 8:
                list.printOrdersHistory();
                break;
            case 9:
                store.calculateRevenue();
                break;    
            case 10:
                store.printSortedOrders();
                break;
            case 11:
                store.createOrder();
                break;
            case 12:
                store.removeOrder();
                break;
            case 13:
                return 0;
            }
            cout << "Do you want to continue (Y/N) ?\n";
            char ch;
            cin >> ch;
            ch = toupper(ch);
            while(cin.fail()){
                cout << "Invalid input! Enter a char value: ";
                cin >> ch;
            }
            while(ch!='Y' && ch!='N'){
                cout << "Enter Y or N : ";
                cin >> ch;
            }
            if(ch=='N'){
                break;
            }
            }
        }
        return 0;
    }
//Customer part
    if(choice==0){
        cout << "We will be happy to serve you.\n"
             << "Would you like to have a shot ? \n"
             << "Sure! choose from the following menu!\n";
    while(true){
            cout<< "=== MENU (We care your choices)===\n"
             << "1. Add item in order.\n"
             << "2. Remove item from the order.\n"
             << "3. Display order details.\n"
             << "4. Calculate bill.\n"
             << "5. Exit.\n";
        int choice;
            cin >> choice;
            while (cin.fail()){
                cout << "Invalid input! Enter integer value 1-8 : ";
                cin >> choice;
            }
            while(choice<1 || choice>4){
                cout << "Enter choice b/w 1-4 : ";
                cin >> choice;
            }

            switch(choice){
                case 1: inv.addItem();
                    break;
                case 2: inv.removeItem();
                    break;
                case 3: order.printOrderDetails();
                    break;
                case 4: order.calculateBill();
                    break;
                case 5:
                    return 0;
                } 
        cout<<"Would You Like to Continue (Y/N).\n";
        char ch;
            cin >> ch;
            ch = toupper(ch);
            while(cin.fail()){
                cout << "Invalid input! Enter a char value: ";
                cin >> ch;
            }
            while(ch!='Y' && ch!='N'){
                cout << "Enter Y or N : ";
                cin >> ch;
            }
            if(ch=='N'){
                break;
            }    
    }
    return 0;
}