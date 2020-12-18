#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

#include <memory>

#include "linked_list/Node.hpp"

template<typename T>
class LinkedList{

private:

    std::shared_ptr<Node<T>> head; // the head of the list
    std::shared_ptr<Node<T>> tail; // the tail of the list
    size_t size; // counter for the list size

public:
    typedef  std::shared_ptr<Node<T>> NodePointer;
    LinkedList(): head{nullptr}, tail{nullptr}, size{0} {}
    ~LinkedList() = default;

    // insert methods 
    void add_first(T value);
    void add_last(T value);

    // remove methods
    bool remove_first();
    bool remove_last();
    bool remove_val_first(T value);
    bool remove_val_last(T value);

    // display list values
    void display()const;
    size_t get_size()const;

};


/*
 * void LinkedList<T>::add_first(T value) 
 * insert the value to the front of the list
*/
template<typename T>
void LinkedList<T>::add_first(T value){
    std::shared_ptr<Node<T>> node_ptr = std::make_shared<Node<T>>(value);
    if(this->head == nullptr){
        this->head = node_ptr;
        this->tail = node_ptr;
    }else{
        node_ptr->next_ptr = this->head;
        head->previous_ptr = node_ptr; 
        this->head = node_ptr;
    }
    this->size++;
}

/*
 * void LinkedList<T>::add_last(T value)
 * insert the value at the end of the list
*/
template<typename T>
void LinkedList<T>::add_last(T value){
    std::shared_ptr<Node<T>> node_ptr = std::make_shared<Node<T>>(value);
    if(this->tail == nullptr){
        this->head = node_ptr;
        this->tail = node_ptr; 
    }else{
        this->tail->next_ptr = node_ptr;
        node_ptr->previous_ptr = this->tail;
        this->tail = node_ptr;
    }
    this->size++;
}

/*
 * bool LinkedList<T>::remove_first()
 * remove the first item in the list, 
 * return false if the list is empty
*/
template<typename T>
bool LinkedList<T>::remove_first(){
    if(this->head == nullptr)
        return false;
    this->head = this->head->next_ptr;
    if(this->head != nullptr)
        this->head->previous_ptr = nullptr;
    else
        this->tail = nullptr; 
    this->size--;
    return true;
}

template<typename T>
bool LinkedList<T>::remove_last(){
    if(this->head == nullptr)
        return false;
    
    this->tail = this->tail->previous_ptr;
    if(this-> tail != nullptr)
        this->tail->next_ptr = nullptr;  
    else
        this->head = nullptr;
    this->size--;
    return true;
}

/*
 * void LinkedList<T>::display() const
 * display the list elements from the front to the end
*/
template<typename T>
void LinkedList<T>::display() const{
    std::shared_ptr<Node<T>> itr = this->head;
    std::cout << "[ ";
    while(itr != nullptr){
        std::cout << itr->value << " ";
        itr = itr->next_ptr;
    }
    std:: cout << "]" << std::endl;
}




/*
 * size_t LinkedList<T>::get_size()const
 * return the current size of the list
*/
template<typename T>
size_t LinkedList<T>::get_size()const{
    return this->size;
}

#endif//_LIKED_LIST_HPP