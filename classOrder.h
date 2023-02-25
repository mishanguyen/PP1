/* Class definitions for Pizza and Pasta, which are going to be used for templated queue. 
A customer can only order either pizza or pasta. */
/* TODO: 
- Subclass PastaOrder and its functions
*/

#ifndef CLASSORDER_H
#define CLASSORDER_H
#include <iostream>
#include <cstdlib>
#include <string>
enum PizzaType { Margherita = 12, Pepperoni = 13, Cheese = 14, Vegetarian = 13, BBQChicken = 16 };
enum CrustType { thin = 1, thick = 0, stuffed = 1};
using namespace std;

// Parent abstract class Order
class Order {
    protected:
        string name;
        string phone;
        string drink;
        double total;
    public:
        Order() {
            cout << "Enter your name: ";
            getline(cin, name);
            cout << "Enter your phone number: ";
            getline(cin, phone);
            cout << "Nice to meet you, " << name << "!" << endl;
            cout << "What drink would you like? Enter drink or \"none\": ";
            getline(cin, drink);
        } // default constructor
        Order(string name, string phone, string drink, double total) // full constructor
            : name(name), phone(phone), drink(drink), total(total) {}
        virtual void printOrder() = 0; // pure virtual function to print order details
        double getTotal() const { return total; }
        string getName() const { return name; }
        string getPhone() const { return phone; }
        string getDrink() const { return drink; }
        void setName(const string& newName) { name = newName; }
        void setPhone(const string& newPhone) { phone = newPhone; }
        void setDrink(const string& newDrink) { drink = newDrink; }
        void setTotal(int newTotal) { total = newTotal; }
};

// Derived class of Order: Pizza
class PizzaOrder : public Order {
    private:
        PizzaType type;
        int size;
        CrustType crust;
        string* toppings;
    public:
        PizzaOrder() {}
        PizzaOrder(PizzaType type = Margherita, int size = 0, CrustType crust = thin, string* toppings = nullptr) 
        : Order(name, phone, drink, total) {};
        PizzaType getType() const { return type; }
        int getSize() const { return size; }
        CrustType getCrust() const { return crust; }
        void getToppings();
        virtual void printOrder() override;
};

// Function to print out the list of toppings
void PizzaOrder::getToppings()  { 
    for (int i = 0; i < toppings->size(); i++) {
        if (toppings->size() == 0) {
            cout << "none";
        } else if (i != toppings->size() - 1) {
            cout << toppings[i] << ", ";
        } else {
            cout << toppings[i];
        }
    }
};

// Function to print the pizza order, overrides the function in the parent class
void PizzaOrder::printOrder() {
    cout << "Drink: " << getDrink() << endl;
    cout << "Pizza Type: " << type << endl;
    cout << "Size: " << size << endl;
    cout << "Crust: " << crust << endl;
    cout << "Toppings: "; getToppings(); cout << endl; 
}

#endif