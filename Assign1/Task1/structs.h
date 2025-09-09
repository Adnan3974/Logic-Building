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

friend istream &operator>>(istream &is,Items&);
void changeItemName(Order& order);
void changeItemPrice(Order& order);
void addQuantity(Order& order);
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
    void addItem(const Items&);
    void removeItem(const Items&);
    void printInventory();
};

struct Order{
    int OrderID;
    Items *items;
    int itemsCount=0;
    int itemsCapacity;
    int *quantities; 
    int quantityCount;
    int quantityCapacity;
    double basePrice=0;
    double tax;
    double totalPrice=0;
    string paymentMethod; 
    string status; 

    Order(){
        OrderID = 0;
        itemsCapacity = 10;
        quantityCapacity = 10;
        items = new Items[itemsCapacity];
        quantities = new int[quantityCapacity];
    }

    void resizeItems();
    void resizeQuantity();
    void addItemInOrder(const Items&);
    void removeItemFromOrder(const Items&);
    void printOrderDetails();
    void calculateBill(); 
};
//orders history
struct Node{
    Order *orders; //Preserve history of orders
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

    void addHistory(const Order&);
    void resizeNodeItems();
    void resizeQuantities();
    void resizeOrders();
    void resizePendingOrders();
};

class List{
    Node *head;
    public:
    List(){
        head = NULL;
    }
    void addOrder(Items&, Order&);
    void removeOrder();
    void printOrdersHistory();
};

struct Store{
    Inventory inventory;
    Order *orders;//orders history
    double totalRevenue;
    void createOrder();
    void removeOrder();
    void printSortedOrders();//ascending sorting by price
    void calculateRevenue();
};