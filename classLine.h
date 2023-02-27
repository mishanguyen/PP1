/* Queue implementation using Customers as nodes of the circularly linked list */
/* Here we don't input the name */
/* TODO: 
- front(): get info about the current customer
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
    public:
        Line() { 
            front = nullptr; 
            rear = nullptr; 
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
        bool empty() const { return (front == nullptr); }
        void enqueue();
        void dequeue();
        void print();
        void clear();
};   

template <typename E>
void Line<E>::enqueue() {
    Customer<E>* newCustomer = new Customer<E>();
    if (empty()) {
        front = newCustomer;
        rear = newCustomer;
        rear->next = front;
        return;
    }
    rear->next = newCustomer;
    rear = newCustomer;
    rear->next = front;
}

template <typename E>
void Line<E>::dequeue() {
    if (empty()) {
        cout << "Line has no customers!" << endl;
    } else if (front == rear) {
        delete front;
        front = nullptr;
        rear = nullptr;
    } else {
        Customer<E>* temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
    }
}

template <typename E>
void Line<E>::print() {
    Customer<E>* cur = front;
    if (cur == rear) {
        cout << cur->order.getName() << endl;
        return;
    }
    while (cur != rear) {
        cout << cur->order.getName() << endl;
        cur = cur->next;
    }
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