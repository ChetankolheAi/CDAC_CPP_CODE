#include <iostream>
using namespace std;

class Customer {
    int customerID;
    string customerName;
    long long customerNumber;

public:
    Customer(int id, string name, long long number) {
        customerID = id;
        customerName = name;
        customerNumber = number;
    }
    void displayCustomer() {
        cout << "Coustomer name :- " << customerName << endl;
        cout << "Coustomer ID:- " << customerID << endl;
        cout << "CoustomerNumber :- " << customerNumber << endl;
    }

};


class Product {
    int productID;
    string productName;
    float price;
    int quantity;
    float Total;

public:

    Product(int id, string name, float p, int q) {
        productID = id;
        productName = name;
        price = p;
        quantity = q;
        Total = 0;
    }
    void display() {
        cout << "Product ID :- " << productID << endl;
        cout << "Produce Name :- " << productName << endl;
        cout << "Price :- " << price << endl;
        cout << "Quantity :- " << quantity;
    }
    float getTotal() {
        Total = price * quantity;
        return Total;
    }



};


class Order {
    int orderID;

    Customer c;
    Product p;

public:

    Order(int oid, int cid, string cname, long long cnumber, int pid, string pname, float price, int quantity)
        : orderID(oid), c(cid, cname, cnumber), p(pid, pname, price, quantity) {
    }


    void displayOrder() {
        cout << "\n===== ORDER DETAILS =====" << endl;

        cout << "Order ID: " << orderID << endl;

        cout << "\n--- Customer Details ---" << endl;
        c.displayCustomer();

        cout << "\n--- Product Details ---" << endl;
        p.display();

        cout << "\nTotal Amount: " << p.getTotal() << endl;
    }


};


int main() {
    Order ord(101, 1, "Alice Smith", 9876543210LL, 501, "Laptop", 750.50f, 2);
    Order ord1(102, 2, "Bob Jones", 9123456789LL, 502, "Smartphone", 499.99f, 1);
    Order ord2(103, 3, "Charlie Brown", 9988776655LL, 503, "Wireless Mouse", 25.50f, 3);
    Order ord3(104, 4, "Diana Prince", 9112233445LL, 504, "Mechanical Keyboard", 89.99f, 2);
    Order ord4(105, 5, "Ethan Hunt", 9554433221LL, 505, "UltraWide Monitor", 349.00f, 1);
    Order ord5(106, 6, "Fiona Glenanne", 9443322110LL, 506, "USB-C Hub", 45.75f, 4);


    ord.displayOrder();
    ord1.displayOrder();
    ord2.displayOrder();
    ord3.displayOrder();
    ord4.displayOrder();
    ord5.displayOrder();

    return 0;
}