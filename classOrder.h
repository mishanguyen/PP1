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
#include <vector>
enum PizzaType { Margherita = 12, Pepperoni = 13, Cheese = 14, Vegetarian = 13, BBQChicken = 16 };
enum CrustType { thin = 0, thick = 1, stuffed = 2};
using namespace std;

// Parent abstract class Order
class Order {
    protected:
        string name;
        string phone;
        string drink;
        double total;
    public:
        Order(); // default constructor
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
        // vector<string> toppings;
    public:
        PizzaOrder();
        PizzaType getType() const { return type; }
        int getSize() const { return size; }
        CrustType getCrust() const { return crust; }
        // void getToppings();
        virtual void printOrder() override;
};

// Constructor for Order 
Order::Order() {
    cin.ignore();
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your phone number: ";
    getline(cin, phone);
    cout << "Nice to meet you, " << name << "!" << endl;
    cout << "What drink would you like? Enter drink or \"none\": ";
    getline(cin, drink);
    total = 0;
}

// Constructor for PizzaOrder
PizzaOrder::PizzaOrder() : Order() {
    // inputting pizza type
    bool valid = 0;
    while (!valid) {
        cout << endl;
        cout << "Choose pizza type:" << endl;
        cout << "1. Margherita ($12)" << endl;
        cout << "2. Pepperoni ($13)" << endl;
        cout << "3. Cheese ($14)" << endl;
        cout << "4. Vegeterian ($13)" << endl;
        cout << "5. BBQ Chicken ($16)" << endl;
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
    // inputting size
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
    cout << endl;
    cout << "Great choice, " << name << "!" << endl;
    // inputting crust
    valid = 0;
    while (!valid) {
        cout << endl;
        cout << "Now, choose the crust:" << endl;
        cout << "1. Thin (+$0)" << endl;
        cout << "2. Thick (+$1)" << endl;
        cout << "3. Stuffed (+$2)" << endl;
        cout << endl;
        char crustChoice;
        cout << "Enter your choice: ";
        cin >> crustChoice;
        switch (crustChoice) {
            case '1':   crust = thin;
                        valid = 1;
                        break;
            case '2':   size = thick;
                        total += thick;
                        valid = 1;
                        break;
            case '3':   size = stuffed;
                        total += stuffed;
                        valid = 1;
                        break;
            default:    cout << "Invalid choice. Please try again. " << endl;
                        break;
        }
    }
    // cout << endl;
    // cout << "Perfect!" << endl;
    // inputting toppings
    // cin.ignore();
    // string topping;
    // while (getline(cin, topping)) {
    //     if (topping == "\n") {
    //         break;
    //     }
    //     toppings.push_back(topping);
    // }
    cout << endl;
    cout << "You're all set! Thanks for your order!" << endl;
}

// Function to print out the list of toppings
// void PizzaOrder::getToppings()  { 
//     for (int i = 0; i < toppings.size(); i++) {
//         if (toppings[0] == "") {
//             cout << "none" << endl;
//             return;
//         } else if (i == toppings.size() - 1){
//             cout << toppings[i] << "." << endl;
//         } else {
//             cout << toppings[i] << ", " << endl;
//         }
//     }
// };

// Function to print the pizza order, overrides the function in the parent class
void PizzaOrder::printOrder() {
    cout << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Drink: " << drink << endl;
    cout << "Pizza Type: " << type << endl;
    cout << "Size: " << size << endl;
    cout << "Crust: " << crust << endl;
    cout << "Total: $" << total << endl;
    // cout << "Toppings: "; getToppings(); cout << endl; 
}

#endif