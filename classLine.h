/* Queue implementation using Customers as nodes of the circularly linked list */
/* Here we don't input the name */
/* TODO: 
- dequeue(): give out the order to the current customer
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
        Node<E>* front;
        Node<E>* rear;
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
        bool empty() const { return (front == nullptr); }
        void enqueue();
        void dequeue();
        void print();
};   

template <typename E>
void Line<E>::enqueue() {
    Customer<E>* newCustomer = new Customer();
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

}
#endif