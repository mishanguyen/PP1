#ifndef CLASSCUSTOMER_H
#define CLASSCUSTOMER_H
#include <iostream>
#include "classLine.h"

template <typename E> class Line;
template <typename E>
class Customer {
    private:
        E* order;
        Customer<E>* next;
    public:
        Customer() {
            order = new E;
        }
        Customer(E* o, Customer<E>* n) : order(o), next(n) {};
    friend class Line<E>;
};

#endif