/* Class definitions for Pizza and Pasta, which are going to be used for templated queue. 
A customer can only order either pizza or pasta. */
/* TODO: 
- Input for crust and toppings
- Print order name, phone, drink, total;
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
            cin.ignore();
            cout << "Enter your name: ";
            getline(cin, name);
            cout << "Enter your phone number: ";
            getline(cin, phone);
            cout << "Nice to meet you, " << name << "!" << endl;
            cout << "What drink would you like? Enter drink or \"none\": ";
            getline(cin, drink);
            total = 0;
        } // default constructor
        // Order(string name, string phone, string drink, double total) // full constructor
        //     : name(name), phone(phone), drink(drink), total(total) {}
        virtual void printOrder() = 0; // pure virtual function to print order details
        // accessor functions
        double getTotal() const { return total; }
        string getName() const { return name; }
        string getPhone() const { return phone; }
        string getDrink() const { return drink; }
        // modifier functions
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
        PizzaOrder() : Order() {
            // chooseing pizza type
            bool valid = 0;
            while (!valid) {
                cout << endl;
                cout << "Choose pizza type:" << endl;
                cout << "1. Margherita" << endl;
                cout << "2. Pepperoni" << endl;
                cout << "3. Cheese" << endl;
                cout << "4. Vegeterian" << endl;
                cout << "5. BBQ Chicken" << endl;
                cout << endl;
                char pizzaChoice;
                cout << "Enter your choice: ";
                cin >> pizzaChoice;
                switch (pizzaChoice) {
                    case '1':   total += Margherita;
                                type = Margherita;
                                valid = 1;
                                break;
                    case '2':   total += Pepperoni;
                                type = Pepperoni;
                                valid = 1;
                                break;
                    case '3':   total += Cheese;
                                type = Cheese;
                                valid = 1;
                                break;
                    case '4':   total += Vegetarian;
                                type = Vegetarian;
                                valid = 1;
                                break;
                    case '5':   total += BBQChicken;
                                type = BBQChicken;
                                valid = 1;
                                break;
                    default:    cout << "Invalid choice. Please try again. " << endl;
                                break;
                }
            }
            cout << endl;
            cout << "Wonderful choice, " << name << "!" << endl;
            valid = 0;
            while (!valid) {
                cout << endl;
                cout << "Let's choose the size:" << endl;
                cout << "1. 14\" (+$0)" << endl;
                cout << "2. 16\" (+$2)" << endl;
                cout << "3. 18\" (+$4)" << endl;
                cout << endl;
                char sizeChoice;
                cout << "Enter your choice: ";
                cin >> sizeChoice;
                switch (sizeChoice) {
                    case '1':   size = 14;
                                valid = 1;
                                break;
                    case '2':   size = 16;
                                total += 2.0;
                                valid = 1;
                                break;
                    case '3':   size = 18;
                                total += 4.0;
                                valid = 1;
                                break;
                    default:    cout << "Invalid choice. Please try again. " << endl;
                                break;
                }
            }

        }
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