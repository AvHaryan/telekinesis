#ifndef FORWARD_H
#define FORWARD_H
#include <initializer_list>

template <typename T>
class Forward_List {

private:
    struct node {
        T data;
        node* next;
        node(const T& value) 
            : data(value)
            , next{nullptr}
        {}
    };
    node* head;

public:
    Forward_List();
    Forward_List(std::initializer_list<T>);
    Forward_List(const T& val);
    Forward_List(const Forward_List<T>& other);
    Forward_List(Forward_List<T>&& other);
   ~Forward_List();

public:
   Forward_List<T>& operator=(const Forward_List<T>& rhv);
   Forward_List<T>& operator=(Forward_List<T>&& rhv);

public:
   void push_front(const T& val);
   void push_back(const T& val);
   void display() const;

};

#include "forward.hpp"
#endif
