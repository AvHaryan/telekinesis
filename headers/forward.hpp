#include "forward.h"
#include <iostream>

template <typename T>
Forward_List<T>::
      Forward_List() : head {nullptr} {}

template <typename T>
Forward_List<T>::
     ~Forward_List() {
         while(head) {
             node* tmp = head;
             head = head->next;
             delete tmp;
         }
     }
         
template <typename T>
void Forward_List<T>::
     push_front(const T& val) {
         node* newNode = new node(val);
         newNode->next = head;
         head = newNode;
     }


template <typename T> 
void Forward_List<T>::
    display() const {
        node* tmp = head;
        while(tmp) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl; 
    }

template <typename T>
void Forward_List<T>::
   push_back(const T& val) {
       node* newNode = new node(val);
       if(!head){
           head = newNode;
           return;
       }
       node* tmp = head;
       while(tmp->next) {
           tmp = tmp->next;
       }
       tmp->next = newNode;
   }

template <typename T>
Forward_List<T>::
    Forward_List(std::initializer_list<T> initList) : 
        head{nullptr} 
        {
        for (const T& elem : initList) {
            push_back(elem);
        }
    }

template <typename T>
Forward_List<T>::
   Forward_List(const T& val) {
       head = new node(val);
   }

template <typename T>
Forward_List<T>::
   Forward_List(const Forward_List<T>& oth) 
      : head(nullptr) {
          if(oth.head) {
              this->head = new node(oth.head->data);
              node* current = this->head;
              node* othCurrent = oth.head->next;
              while(othCurrent) {
                  current->next = new node(othCurrent->data);
                  current = current->next;
                  othCurrent = othCurrent->next;
              }
          }
      }

template <typename T>
Forward_List<T>::
   Forward_List(Forward_List<T>&& other) 
      : head(nullptr) {
          head = other.head;
          other.head = nullptr;
      }

template <typename T>
Forward_List<T>& Forward_List<T>::
   operator=(const Forward_List<T>& rhv) {
       if(this != &rhv) {

          while(this->head) {
              node* tmp = head;
              head = head->next;
              delete tmp;
          }

          if(rhv.head) {
             this->head = new node(rhv.head->data);
             node* current = this->head;
             node* othCurrent = rhv.head->next;
             while(othCurrent) {
                 current->next = new node(othCurrent->data);
                 current = current->next;
                 othCurrent = othCurrent->next;
             }
          }
       }
       return *this;
   }
                   
template <typename T>
Forward_List<T>& Forward_List<T>::
   operator=(Forward_List<T>&& rhv) {
       if (this != &rhv) {
           while(this->head) {
               node* tmp = head;
               head = head->next;
               delete tmp;
           }
           this->head = rhv.head;
           rhv.head = nullptr;
       }
       return *this;
   }

