#include<iostream>
#include<string>
#include "structs.h"
using namespace std;
//reflect change of item's name in orders 
void Items::changeItemName(Order& order){
    cout << "Enter the new name: ";
    string n;
    getline(cin, n);
    while(n.empty()){
        cout << "Name can't be empty! Re-Enter";
        getline(cin, n);
    }
    
    name = n; //name locally changed
    if(order.items->barcode==barcode){
        order.items->name = n;//Changes reflect in order
    }
}

void Items::changeItemPrice(Order& order){
    cout << "Enter the new price: ";
    double p;
    cin >> p;
    while(cin.fail()){
        cout << "Invalid data type! Re-Enter";
        cin >> p;
    }
    price = p;
    if(order.items->barcode==barcode){
        order.items->price = p;//Changes reflect in order
    }
}

void Items::addQuantity(Order& order){
    cout << "Enter quantity to add: ";
    int n;
    cin >> n;
    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Invalid data type! Re-Enter";
        cin >> n;
    }
    quantity += n;
    if(order.items->barcode==barcode){
        order.items->quantity = quantity;//Changes reflect in order
    }
}

void Items::printItemDetails(){
    cout << "Name: " << name << "\n"
         << "Barcode: " << barcode << "\n"
         << "Price: " << price << "\n"
         << "Quantity: " << quantity<< "\n";
}

void Inventory::resize(){
    int newCapacity = capacity * 2;
    Items *newItems = new Items[newCapacity];
    for (int i = 0; i < count; ++i){
        newItems[i] = items[i];
    }
    delete[] items;
    items = newItems;
    capacity = newCapacity;
}

void Inventory::addItem(const Items& newItem){
    for (int i = 0; i < count; ++i){
        if(items[i].barcode==newItem.barcode){
            items[i].quantity++;
            return;
        }
    }

    if (count >= capacity) {
            resize();
    }
    items[count++] = newItem;
}

void Inventory::removeItem(const Items& prevItem){
for (int i = 0; i < count; ++i){
        if(items[i].barcode==prevItem.barcode){
            items[i].quantity--;
            return;
        }
    }
    cout << "The item doesn't exist!\n";
}

void Inventory::printInventory(){
    for(int i=0; i<count; ++i){
        cout << "Item Name: " << items[i].name << "\n"
            <<"Barcode: "<<items[i].barcode<<"\n"
             << "Price: " << items[i].price << "\n"
             << "Quantity: " << items[i].quantity << "\n";
    }
}

Inventory::~Inventory(){
    delete[] items;
}

void Order::resizeItems(){
    int newItemsCapacity=itemsCapacity*2;
    Items *moreItems = new Items[newItemsCapacity];
    for (int i = 0; i < itemsCount; ++i){
        moreItems[i] = items[i];
    }
    delete[] items;
    items = moreItems;
    itemsCapacity = newItemsCapacity;
}

    void Order::resizeQuantity(){
        int newQuantity = quantityCount * 2;
        int* newQuantArray = new int[newQuantity];
        for (int i = 0; i<quantityCount; ++i){
            newQuantArray[i] = quantities[i];
        }
        delete[] quantities;
        quantities = newQuantArray;
        quantityCount = newQuantity;
    }

    void Order::addItemInOrder(const Items& addedItem){
        for (int i = 0; i<itemsCount; ++i){
            if(items[i].barcode==addedItem.barcode)
                quantities[i]++;
            return;
        }

        if (itemsCount >= itemsCapacity) {
            resizeItems();
        }
        items[itemsCount++] = addedItem;
    }

    void Order::removeItemFromOrder(const Items& removedItem){
        for (int i = 0; i<itemsCount; ++i){
            if(items[i].barcode==removedItem.barcode)
                quantities[i]--;
            return;
        }
        cout << "The item doesn't belong to your order!\n";
    }

    void Order::printOrderDetails(){
        
        if(itemsCount==0){
            cout << "Please order some stuff! Nothing in the orderlist to display\n";
            return;
        }

        for (int i = 0; i<itemsCount; ++i){
            cout << "Item Name: " << items[i].name << "\n"
                 << "Barcode: " << items[i].barcode << "\n"
                 << "Price: " << items[i].price << "\n"
                 << "Quantity: " << items[i].quantity << "\n";
        }
    }

    void Order::calculateBill(){
        
        if(itemsCount==0){
            cout << "Please order some stuff! Nothing in the orderlist to calculate\n";
            return;
        }

        

        cout << "Enter your payment method Cash/Card (1/0): ";
        int choice;
        cin >> choice;
        while(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Enter integer value: ";
            cin >> choice;
        }
        while(choice!=0 || choice!=1){
            cout << "Invalid choice! \nEnter 1 for Cash or 0 for Card";
            cin >> choice;
        }

        (choice == 1) ? tax = 15 : tax = 5;
        for (int i = 0; i < itemsCount; ++i)
        {
            basePrice += quantities[i] * items[i].price;
        }
        totalPrice += basePrice * tax;
        cout << "Base Payment = " << basePrice << "\n"
             << "Total Payment (includes tax) = " << totalPrice << "\n";
        cout << "Do you want to pay now or later (1/0) ?\n";
        int ch;
        cin >> ch;
        while(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Enter integer value: ";
            cin >> ch;
        }
        while(ch!=1 || ch!=0){
            cout << "Invalid choice!\n Enter 1 for now or 0 for later payment: ";
            cin >> ch;
        }

        if(ch==1){
            cout << "Enter the amount: ";
            int amount;
            while(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Enter integer value: ";
            cin >> ch;
            }
            while (amount<totalPrice){
                cout << "Insufficient amount!\nRetry: ";
                cin >> amount;
            }
        }
        (ch == 1) ? OrderID += 2 : OrderID += 1;//If even ->completed, if Odd->Pending
        (ch == 1) ? status = "Completed" : status = "Pending";
    } 

    Order::~Order(){
        delete[] items;
        delete[] quantities;
    }

    void Node::addHistory(const Order& order){
        if(order.itemsCount>itemCapacity){
            resizeNodeItems();
        }
        if(order.quantityCount>quantitiesCapacity){
            resizeQuantities();
        }

        for (int i = 0; i < order.itemsCount; ++i){
            items[i] = order.items[i];
            quantities[i] = order.quantities[i];
            basePrice = order.basePrice;
            tax = order.tax;
            totalPrice = order.totalPrice;
            paymentMethod = order.paymentMethod;
            status = order.status;
        }
    }

    void Node::resizeNodeItems(){
        int newCapacity = itemCapacity * 2;
        Items *newNode = new Items[newCapacity];
        for (int i = 0; i < itemCapacity; ++i){
            newNode[i] = items[i];
        }
        delete[] items;
        items = newNode;
        itemCapacity = newCapacity;
    }

    void Node::resizeQuantities(){
        int newQuantitiesCapacity = quantitiesCapacity * 2;
        int *newQuantities = new int[newQuantitiesCapacity];

        for(int i=0; i<quantitiesCapacity; ++i){
            newQuantities[i] = quantities[i];
        }
        delete[] quantities;
        quantities = newQuantities;
        quantitiesCapacity = newQuantitiesCapacity;
    }

istream &operator>>(istream &in,Items& item){
    in >> item.name>>item.barcode>>item.price>>item.quantity;
    return in;
}

void List::addOrder(Items& item, Order& order){
    while(true){
    cout << "Enter item Name: ";
    cin >> item.name;
    cout << "Enter Barcode: ";
    cin >> item.barcode;
    cout << "Enter Price: ";
    cin >> item.price;
    cout << "Enter Quantity: ";
    cin >> item.quantity;
    order.addItemInOrder(item);
    cout << "Do you want to add more items in this order (1/0) ?";
    int choice;
    cin >> choice;
    while(cin.fail()){
        cout << "Enter an integer value: ";
        cin >> choice;
    }
    while(choice!=1 || choice!=0){
        cout << "Enter valid input! 1 for \"Yes\" and 0 for \"No\"";
        cin >> choice;
    }
    if(choice==0){
        break;
    }
    }
}

    void List::removeOrder(){
        
    }
    void printOrdersHistory();
