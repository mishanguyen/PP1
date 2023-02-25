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

#endif