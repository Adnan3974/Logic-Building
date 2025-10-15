#include<iostream>
#include<string>
#include "structs.h"
using namespace std;
struct Inventory;
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

void Order::removeItemFromOrder(){
    if (inventory == nullptr) {
        cout << "Error: Order not properly initialized with inventory!\n";
        return;
    }

    cout << "Enter item's barcode: ";
    int b;
    cin >> b;
    bool status = false;
    
    for (int i = 0; i < itemsCount; ++i){
        if (items[i].barcode == b){ 
            // Return item to inventory
            for(int j = 0; j < inventory->count; ++j){
                if(inventory->items[j].barcode == b){
                    inventory->items[j].quantity += quantities[i];
                    break;
                }
            }
          
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


Order::Order(Inventory* inv) : inventory(inv) {
    itemsCapacity = 10;
    quantityCapacity = 10;
    itemsCount = 0;
    quantityCount = 0;
    tax = 0;
    basePrice = 0;
    totalPrice = 0;
    items = new Items[itemsCapacity];
    quantities = new int[quantityCapacity];
    status = "Pending";
    paymentMethod = "";
}

void Order::addItemInOrder(){
    if (inventory == nullptr) {
        cout << "Error: Order not properly initialized with inventory!\n";
        return;
    }

    if (itemsCount >= itemsCapacity){
        resizeItems();
    }    
    cout << "Enter item name: ";
    string itemName;
    cin.ignore();
    getline(cin, itemName);
    bool status = false;
    
    for(int i = 0; i < inventory->count; ++i){
        if(inventory->items[i].name == itemName && inventory->items[i].quantity > 0){
            items[itemsCount] = inventory->items[i];
            quantities[itemsCount] = 1; 
            inventory->items[i].quantity--; 
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
    if(head==NULL){
        head = new Node();
    }
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
    if(head == NULL){
        cout<<"No Orders Exist Yet.\n";
        return;
    }
    
    Node* temp = head;
    while(temp != NULL){
        for (int i = 0; i < temp->ordersCount; ++i) {
            if(temp->orders[i].items != nullptr && temp->orders[i].itemsCount > 0){
                for(int j = 0; j < temp->orders[i].itemsCount; ++j){
                    cout << "Item Name: " << temp->orders[i].items[j].name << "\n"
                         << "Barcode: " << temp->orders[i].items[j].barcode << "\n"
                         << "Price: " << temp->orders[i].items[j].price << "\n"
                         << "Quantity: " << temp->orders[i].quantities[j] << "\n"; // Use quantities array
                }
                cout << "Total Price: " << temp->orders[i].totalPrice << "\n"
                     << "Status: " << temp->orders[i].status << "\n";
            }
        }
        temp = temp->next;
    }
}


void Store::calculateRevenue(){
    for(int i = 0; i < node.ordersCount; ++i){
        if(node.orders[i].status == "Completed"){
            totalRevenue += node.orders[i].totalPrice;
        }
    }
    cout << "Total Revenue: $" << totalRevenue << "\n";
}

void Store::createOrder(){
    if (node.ordersCount >= node.ordersCapacity) {
        node.resizeOrdersCapacity();
    }
    for (int i = 0; i < node.pendingOrdersCount; i++) {
        if (node.pendingOrders[i].status == "Completed") {
            node.orders[node.ordersCount] = node.pendingOrders[i];
            node.ordersCount++;
            
            // Remove from pending orders
            for (int j = i; j < node.pendingOrdersCount - 1; j++) {
                node.pendingOrders[j] = node.pendingOrders[j + 1];
            }
            node.pendingOrdersCount--;
            i--; // Adjust index after removal
            
            cout << "Order added to history successfully.\n";
        }
    }
}

void Store::removeOrder(){
    cout << "Enter the order index to remove (0 to " << node.ordersCount - 1 << "): ";
    int index;
    cin >> index;
    
    if (index < 0 || index >= node.ordersCount) {
        cout << "Invalid order index!\n";
        return;
    }
    for (int i = index; i < node.ordersCount - 1; i++) {
        node.orders[i] = node.orders[i + 1];
    }
    node.ordersCount--;
    
    cout << "Order removed from history successfully.\n";
}

void Store::printSortedOrders(){
    if(node.ordersCount == 0){
        cout << "No orders to sort.\n";
        return;
    }
    Order* tempOrders = new Order[node.ordersCount];
    for(int i = 0; i < node.ordersCount; ++i){
        tempOrders[i] = node.orders[i];
    }
    //sorting algorithm
    for(int i = 0; i < node.ordersCount-1; ++i){
        for(int j = i+1; j < node.ordersCount; ++j){    
            if(tempOrders[i].basePrice > tempOrders[j].basePrice){
                swap(tempOrders[i], tempOrders[j]);
            }
        }
    }

    for (int i = 0; i < node.ordersCount; ++i){
        cout << "Order " << i+1 << " Total: $" << tempOrders[i].totalPrice << "\n";
        for (int j = 0; j < tempOrders[i].itemsCount; ++j){
            cout << "  " << tempOrders[i].items[j].name << " x" << tempOrders[i].quantities[j] << "\n";
        }
    }
    delete[] tempOrders;
}
