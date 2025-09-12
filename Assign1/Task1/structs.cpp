#include<iostream>
#include<string>
#include "structs.h"
using namespace std;
void Items::changeItemName(){ 
    cout << "Enter the new name: ";
    string n;
    cin.ignore();
    getline(cin, n);
    while(n.empty()){
        cout << "Name can't be empty! Re-Enter";
        getline(cin, n);
    }
    name = n; 
    cout<<"Items name changed successfully.\n";
}

void Items::changeItemPrice(){
    cout << "Enter the new price: ";
    double p;
    cin >> p;
    while(cin.fail() || p < 0){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid price! Re-Enter: ";
        cin >> p;
    }
    price = p;
    cout << "Item price successfully changed.\n";
}

void Items::addQuantity(){
    cout << "Enter quantity to add: ";
    int n;
    cin >> n;
    while(cin.fail() || n < 0){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid quantity! Re-Enter: ";
        cin >> n;
    }
    quantity += n;
    cout << n << " Items added into " << name << "\n";
}

void Items::printItemDetails(){
    if (name.empty()) {
        cout << "No item details to display.\n";
        return;
    }
    cout << "Name: " << name << "\n"
         << "Barcode: " << barcode << "\n"
         << "Price: " << price << "\n"
         << "Quantity: " << quantity << "\n";
}

void Inventory::resize(){
    capacity *= 2;
    Items *newItems = new Items[capacity];
    for (int i = 0; i < count; ++i){
        newItems[i] = items[i];
    }
    delete[] items;
    items = newItems;
}
//Admin adds item
void Inventory::addItem(){
    Items newItem;
    if (count >= capacity)
    {
        resize();
    }
    cout << "Enter items name: ";
    cin.ignore();
    getline(cin, newItem.name);
    while (newItem.name.empty()) {
        cout << "Name can't be empty! Re-Enter: ";
        getline(cin, newItem.name);
    }

    cout << "Enter items barcode: ";
    cin >> newItem.barcode;
    while (cin.fail() || newItem.barcode < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid barcode! Re-Enter: ";
        cin >> newItem.barcode;
    }

    cout << "Enter items price: ";
    cin >> newItem.price;
    while (cin.fail() || newItem.price < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid price! Re-Enter: ";
        cin >> newItem.price;
    }

    cout << "Enter items quantity: ";
    cin >> newItem.quantity;
    while (cin.fail() || newItem.quantity < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid quantity! Re-Enter: ";
        cin >> newItem.quantity;
    }

    for (int i = 0; i < count; ++i){
        if(items[i].barcode == newItem.barcode){
            items[i].quantity += newItem.quantity;
            cout << "Item added successfully!\n";
            return;
        }
    }
    items[count++] = newItem;
    cout << "Item added successfully!\n";
}

void Inventory::removeItem(){
    cout << "Enter the barcode of the item you want to remove: ";
    int b;
    cin >> b;
    bool status = false;
    for (int i = 0; i < count; ++i)
    {
        if(items[i].barcode == b){
            if(items[i].quantity > 0){
                items[i].quantity--;
                cout << "Item removed successfully.\n";
            } else {
                cout << "No quantity left to remove for this item.\n";
            }
            status = true;
            return;
        }
    }
    if(!status){
        cout << "The item doesn't exist!\n";   
    }
}

void Inventory::printInventory(){
    if(count<=0){
        cout<<"Nothing in the inventory to display.\n";
        return;
    }
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
    itemsCapacity*=2;
    Items *moreItems = new Items[itemsCapacity];
    for (int i = 0; i < itemsCount; ++i){
        moreItems[i] = items[i];
    }
    delete[] items;
    items = moreItems;
}
//---Missing quantities array initialization---//
void Order::resizeQuantity(){
        quantityCount *= 2;
        int* newQuantArray = new int[quantityCount];
        for (int i = 0; i<quantityCount/2; ++i){
            newQuantArray[i] = quantities[i];
        }
        delete[] quantities;
        quantities = newQuantArray;
}
//-------BUGS------//
void Order::addItemInOrder(){
    if (itemsCount >= itemsCapacity){
        resizeItems();
    }    
    cout << "Enter item name: ";
    string b;
    cin.ignore();
    getline(cin, b);
    bool status = false;
    for(int i = 0; i < itemsCapacity; ++i){
        if(items[i].name == b && items[i].quantity > 0){
            items[itemsCount] = items[i];
            quantities[itemsCount] = 1; 
            items[i].quantity--; 
            itemsCount++;
            status = true;
            cout << "Item added to order successfully!\n";
            break;
        }
    }
    if(!status){
        cout << "Sorry! Item doesn't exist in the inventory or is out of stock!\n";
    }
}

void Order::removeItemFromOrder(){
    cout << "Enter item's barcode: ";
    int b;
    cin >> b;
    bool status = false;
    for (int i = 0; i < itemsCount; ++i){
        if (items[i].barcode == b){ 
            items[i].quantity++; 
            for (int j = i; j < itemsCount - 1; ++j){
                items[j] = items[j + 1];
                quantities[j] = quantities[j + 1];
            }
            itemsCount--;
            status = true;
            cout << "Item removed from order successfully.\n";
            break;
        }
    }
    if(!status){
        cout << "The item doesn't belong to your order!\n";
    }
}

void Order::printOrderDetails(){
    if(itemsCount<=0){
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
        while(choice!=0 && choice!=1){
            cout << "Invalid choice! \nEnter 1 for Cash or 0 for Card";
            cin >> choice;
        }

        (choice == 1) ? tax = 15 : tax = 5;
        for (int i = 0; i < itemsCount; ++i)
        {
            basePrice += quantities[i] * items[i].price;
        }
        totalPrice = basePrice + (basePrice*tax/100);
        cout << "Base Payment = " << basePrice << "\n"
             << "Total Payment (includes tax) = " << totalPrice << "\n";
        cout << "Do you want to pay now or later (1/0) ?\n";
        int ch;
        cin >> ch;
        while(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Enter integer value: ";
            cin >> ch;
        }
        while(ch!=1 && ch!=0){
            cout << "Invalid choice!\n Enter 1 for now or 0 for later payment: ";
            cin >> ch;
        }
        if(ch==1){
            cout << "Enter the amount: ";
            int amount;
            cin>>amount;
            while(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Enter integer value: ";
            cin >> amount;
            }
            while (amount<totalPrice){
                cout << "Insufficient amount!\nRetry: ";
                cin >> amount;
            }
        }
        (ch == 1) ? status = "Completed" : status = "Pending";
} 

void Node::resizeOrdersCapacity(){
        ordersCapacity*=2;
        Order *newOrder = new Order[ordersCapacity];
        for (int i = 0; i < ordersCount; ++i)
        {
            newOrder[i] = orders[i];
        }
        delete[] orders;
        orders = newOrder;
}

void Node::resizePendingOrdersCapacity(){
        pendingOrdersCapacity*=2;
        Order *newOrder = new Order[pendingOrdersCapacity];
        for (int i = 0; i < pendingOrdersCount; ++i)
        {
            newOrder[i] = pendingOrders[i];
        }
        delete[] pendingOrders;
        pendingOrders = newOrder;
}

void Node::addHistory(const Order& order){
    if(order.status == "Completed"){
        if (ordersCount >= ordersCapacity) {
            resizeOrdersCapacity();
        }
        orders[ordersCount] = order;
        ordersCount++;
        totalOrders++;
    } else {
        if (pendingOrdersCount >= pendingOrdersCapacity) {
            resizePendingOrdersCapacity();
        }
        pendingOrders[pendingOrdersCount] = order;
        pendingOrdersCount++;
        totalOrders++;
    }
}

void Node::resizeNodeItems(){
        itemCapacity *= 2;
        Items *newNode = new Items[itemCapacity];
        for (int i = 0; i < itemCapacity/2; ++i){
            newNode[i] = items[i];
        }
        delete[] items;
        items = newNode;
}

void Node::resizeQuantities(){
        quantitiesCapacity *= 2;
        int *newQuantities = new int[quantitiesCapacity];

        for(int i=0; i<quantitiesCapacity/2; ++i){
            newQuantities[i] = quantities[i];
        }
        delete[] quantities;
        quantities = newQuantities;
}

void List::addOrder(){
for (int i = 0; i < head->ordersCount; ++i) {
        if (head->orders[i].status == "Completed") {
            head->addHistory(head->orders[i]);
        }
    }
}

    void List::removeOrder(){
        if(head==NULL){
            cout<<"Orders don't exist!";
            return;
        }
        for(int i=0; i<head->ordersCount; ++i){
            if(head->orders->status=="Completed"){
                head[i].orders=nullptr;
                break;
            }
            if(head->orders->status=="Pending"){
                head[i].pendingOrders=nullptr;
                break;
            }
        }
    }
    //Only displaying completed orders !Pendings
    void List::printOrdersHistory(){
        if(head==NULL){
            cout<<"No Orders Exist Yet.\n";
            return;
        }
        Node* temp=head;
        
        while(temp!=NULL){
            for (int i = 0; i < temp->ordersCount; ++i) {
            // Print only completed orders
            if (temp->orders[i].status == "Completed") {
                cout << "Order ID: " << temp->orders[i].OrderID << "\n";
                for (int j = 0; j < temp->orders[i].itemsCount; ++j) {
                    cout << "Item Name: " << temp->orders[i].items[j].name << "\n"
                         << "Barcode: " << temp->orders[i].items[j].barcode << "\n"
                         << "Price: " << temp->orders[i].items[j].price << "\n"
                         << "Quantity: " << temp->orders[i].items[j].quantity << "\n";
                }
                cout << "Total Price: " << temp->orders[i].totalPrice << "\n";
                cout << "Status: " << temp->orders[i].status << "\n\n";
            }
        }
            temp=temp->next;
        }
    }

    void Store::calculateRevenue(){
        for (int i = 2; i <= node.orders->OrderID; i += 2){
            totalRevenue += node.orders->totalPrice;
        }
    }

    void Store::createOrder(){
        List list;
        list.addOrder();
    }

    void Store::removeOrder(){
        List list;
        list.removeOrder();
    }

    void Store::printSortedOrders(){
        Node *node;
        for(int i=4; i<node->orders->OrderID-2; i+=2){
            for(int j=2; j<node->orders->OrderID; j+=2){
                if(node->orders[i].basePrice < node->orders[j].basePrice){
                    swap(node->orders[i].basePrice , node->orders[j].basePrice);
                }
            }
        }
        
        for (int i = 2; i < node->totalOrders; i+=2){
            if(node->orders->OrderID==0){
                continue;
            }
            cout << node->orders[i].items[i].name << "\n";
            cout << node->orders[i].items[i].barcode << "\n";
            cout << node->orders[i].items[i].price << "\n";
            cout << node->orders[i].items[i].quantity << "\n";
        }
    }