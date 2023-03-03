/* Queue implementation using Customers as nodes of the circularly linked list */
/* Here we don't input the name */
/* TODO: 
- size(): to see how many people are in the line 
*/
#ifndef CLASSLINE_H
#define CLASSLINE_H
#include <iostream>
#include <cstdlib>
#include "classCustomer.h"

using namespace std;

template <typename E>
class Line {
    private:
        Customer<E>* front;
        Customer<E>* rear;
        int n;
    public:
        Line() { 
            front = nullptr; 
            rear = nullptr; 
            n = 0;
        }
        ~Line() {
            while (!empty()) {
                dequeue();
            }
            delete front;
            delete rear;
        }
        Line& operator=(const Line& copy) {
            if (this == &copy) {
                return *this;
            }
            front = copy.front;
            rear = copy.rear;
            return *this;
        }
        bool empty() const { return (n == 0); }
        void enqueue();
        void dequeue();
        void getFront();
        string getFrontName();
        void clear();
        int size();
};   

template <typename E>
void Line<E>::enqueue() {
    Customer<E>* newCustomer = new Customer<E>();
    if (empty()) {
        front = newCustomer;
        rear = newCustomer;
        rear->next = front;
        cout << endl;
        cout << "Here is your order:" << endl;
        newCustomer->order->printOrder();
        n++;
        return;
    }
    rear->next = newCustomer;
    rear = newCustomer;
    rear->next = front;
    cout << "Here is your order:" << endl;
    newCustomer->order->printOrder();
    n++;
}

template <typename E>
void Line<E>::dequeue() {
    if (empty()) {
        cout << "Line has no customers!" << endl;
    } else if (front == rear) {
        delete front;
        front = nullptr;
        rear = nullptr;
        n--;
    } else {
        Customer<E>* temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
        n--;
    }
}

template <typename E>
void Line<E>::getFront() {
    if (front == nullptr) {
        cout << "There are no customers in line!" << endl;
        return;
    }
    front->order->printOrder();
}

template <typename E>
string Line<E>::getFrontName() {
    return front->order->getName();
}

template <typename E>
int Line<E>::size() {
    return n;
}

template <typename E>
void Line<E>::clear() {
    if (empty()) {
        return;
    }
    else {
        Customer<E>* cur = front;
        while (cur != rear) {
            Customer<E>* temp = cur;
            cur = cur->next;
        }
        front = nullptr;
        rear = nullptr;
    }
}
#endif