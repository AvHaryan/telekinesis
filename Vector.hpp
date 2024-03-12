#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "Vector.h"
#include <iostream>
template <typename value_type>
 Vector<value_type>::Vector() 
    : size{0}
    , capacity{0}
    , arr{nullptr}
{std::cout << "Default Ctor is Called\n";}

template <typename T>
Vector<T>
    ::Vector(const Vector& rhs)
    : size{rhs.size}
    , capacity{rhs.capacity}
    , arr{new T[capacity]}
{
    for (size_t i = 0; i < size; ++i) {
        arr[i] = rhs.arr[i];
    }
    std::cout << "Copy Ctor Is Called \n";
}

template <typename value_type>
Vector<value_type>
    ::Vector(std::initializer_list<value_type> list)
    : size{list.size()}
    , capacity{list.size() * 2}
    , arr{new value_type[capacity]}
{
   value_type* ptr = arr;
  for (auto& element : list) {
     *ptr++ = element;
  }
  std::cout << "IL\n";
} 

template <typename value_type>
Vector<value_type>
   ::Vector(const_reference value)
    : size{1}
    , capacity{2}
    , arr{new value_type(value)}
{}

template <typename value_type>
Vector<value_type>
   ::~Vector() {
       delete[] arr;
       std::cout << "Dtor  is called\n";
   }

template <typename value_type>
void Vector<value_type>
   ::display() const {
       for (size_t i = 0; i < size; ++i) {
           std::cout << arr[i] << " ";
       }
       std::cout << std::endl;
   }

template <typename value_type>
void Vector<value_type>
   ::resize() {
       capacity = (capacity == 0) ? 1 : capacity * 2;
       value_type* tmp = new value_type[capacity];
       for (size_type i = 0; i < size; ++i) {
           tmp[i] = arr[i];
       }
       delete[] arr;
       arr = tmp;
       tmp = nullptr;
   }


template <typename value_type>
void Vector<value_type>
   ::push_back(const_reference data) {
       if (size == capacity) {
           resize();
       }
       arr[size++] = data;
   }

template <typename value_type>
void Vector<value_type>
   ::clear() {
       size = 0;
       capacity = 0;
       delete[] arr;
       arr = nullptr;
   }

template <typename value_type>
void Vector<value_type>
   ::insert(size_type pos, const_reference val) {
       if ((pos > size) || (pos < 0)) {
           return;
       }
       if (size == capacity) {
           resize();
       }
       for (size_t i = size; i > pos; --i) {
           arr[i] = arr[i - 1];
       }
       arr[pos] = val;

       ++size;
   }

template <typename value_type>
void Vector<value_type>
   ::push_front(const_reference val) {
       if (size == capacity) {
           resize();
       }

       for (size_type i = size; i > 0; --i) {
           arr[i] = arr[i - 1];
       }
       arr[0] = val;
       ++size;
   }
#endif
