#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <initializer_list>

template <typename T>
class Vector {

public:
    using value_type = T;
    using size_type = size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;


public:
    Vector();
    Vector(const_reference value);
    Vector(const Vector& rhs);
    Vector(std::initializer_list<value_type> list);
    ~Vector();
    
public:
    void display() const;
    void resize();
    void push_back(const_reference val);
    void clear();
    void insert(size_type pos, const_reference val);
    void push_front(const_reference val);

private:
    size_type size;
    size_type capacity;
    pointer arr;
};
    



#include "Vector.hpp"
#endif //VECTOR_H
