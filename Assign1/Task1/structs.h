#ifndef STRUCTS_H
#define STRUCTS_H
#include<string>
using std::string;

struct Items{
string name;
int barcode;
double price;
int quantity;
Items(){
    name = "";
    barcode =0;
    price = 0;
    quantity = 0;
}

void changeItemName();
void changeItemPrice();
void addQuantity();
void printItemDetails();
};

struct Inventory{
    Items* items;
    int capacity;
    int count;
    
    Inventory(){
        capacity = 10;
        count = 0; 
        items = new Items[capacity];
    }

    ~Inventory();

    void resize();
    void addItem();
    void removeItem();
    void printInventory();
};

struct Order{
    Inventory* inventory;
    Items *items;
    int itemsCount;
    int itemsCapacity;
    int *quantities; 
    int quantityCount;
    int quantityCapacity;
    double basePrice;
    double tax;
    double totalPrice;
    string paymentMethod; 
    string status; 

    Order(Inventory* inv);
    Order(){
        inventory=nullptr;
        itemsCapacity = 10;
        quantityCapacity = 10;
        itemsCount=0;
        tax=0;
        basePrice=0;
        items = new Items[itemsCapacity];
        quantities = new int[quantityCapacity];
        status="Pending";
    }

    void resizeItems();
    void resizeQuantity();
    void addItemInOrder();
    void removeItemFromOrder();
    void printOrderDetails();
    void calculateBill();
};

//orders history
struct Node{
    int totalOrders;
    Order *orders; // Preserve history of orders
    int ordersCapacity;
    int ordersCount;
    Order *pendingOrders;
    int pendingOrdersCapacity;
    int pendingOrdersCount;
    Items *items; // array of items
    int itemCapacity;
    int *quantities; // array of items' quantities
    int quantitiesCapacity;
    
    double basePrice;
    double tax;
    double totalPrice;
    string paymentMethod; 
    string status; 
    Node* next;

    Node(){
        next=NULL;
        totalOrders = 0;
        ordersCapacity = 40;
        ordersCount = 0;
        orders = new Order[ordersCapacity];
        pendingOrdersCapacity = 20;
        pendingOrdersCount = 0;
        pendingOrders = new Order[pendingOrdersCapacity];
        itemCapacity = 40;
        quantitiesCapacity = 40;
        items = new Items[itemCapacity];
        quantities = new int[quantitiesCapacity];
    }

    ~Node() {
        delete[] orders;
        delete[] pendingOrders;
        delete[] items;
        delete[] quantities;
    }
    
    void addHistory(const Order&);
    void resizeNodeItems();
    void resizeQuantities();
    void resizeOrdersCapacity();
    void resizePendingOrdersCapacity();
};

class List{
    Node*  order;
    Node *head;
    public:
    List(){
        head = nullptr;
        order=nullptr;
    }
    void addOrder();
    void removeOrder();
    void printOrdersHistory();
};

struct Store{
    Inventory inventory;
    Order *pendingOrders;//pending orders history
    Order *ordersHistory;
    Node node;
    double totalRevenue;
    void createOrder();
    void removeOrder();
    void printSortedOrders();//ascending sorting by price
    void calculateRevenue();
    Store(){
        pendingOrders = new Order[node.pendingOrdersCapacity];
        ordersHistory = new Order[node.ordersCapacity];
        totalRevenue = 0;
    }
    ~Store() {
        delete[] pendingOrders;
        delete[] ordersHistory;
    }
};

#endif