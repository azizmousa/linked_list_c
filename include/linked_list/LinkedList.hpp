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
    bool remove(T value, bool front);

    // display list values
    void display()const;
    size_t get_size()const;


    // find method
    NodePointer find(T value)const;

    // the stucture iterators
    NodePointer begin()const;
    NodePointer end()const;

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
 * bool LinkedList<T>::remove(T value, bool front)
 * remove the first element that have the specified value
 * start from the front if front = true
*/
template<typename T>
bool LinkedList<T>::remove(T value, bool front){
    if(this->head == nullptr)
        return false;
    NodePointer it;
    if(front)
        it = this->head;
    else
        it = this->tail;

    bool found_flag = false;
    while( it != nullptr){
        if(it->value == value){
            if(it->next_ptr != nullptr)
                it->next_ptr->previous_ptr = it->previous_ptr;
            else
                this->tail = it->previous_ptr;

            if(it->previous_ptr != nullptr)    
                it->previous_ptr->next_ptr = it->next_ptr;
            else
                this->head = it->next_ptr;
            
            it->next_ptr = nullptr;
            it->previous_ptr = nullptr;
            it = nullptr; 
            found_flag = true;
            this->size--;
            break;
        }
        if(front)
            it = it->next_ptr;
        else
            it = it->previous_ptr;
    }
    return found_flag;
}


/*
 * size_t LinkedList<T>::get_size()const
 * return the current size of the list
*/
template<typename T>
size_t LinkedList<T>::get_size()const{
    return this->size;
}


/*
 * std::shared_ptr<Node<T>> LinkedList<T>::find(T value)
 * find the value node and return its pointer
*/
template<typename T>
std::shared_ptr<Node<T>> LinkedList<T>::find(T value)const{
    NodePointer itr = this->head;
    while(itr != nullptr){
        if(itr->value == value)
            return itr;
       itr = itr->next_ptr; 
    }
    return nullptr;
}

/*
 * std::shared_ptr<Node<T>> LinkedList<T>::begin()const
 * return the pointer to the first element in the list
*/
template<typename T>
std::shared_ptr<Node<T>> LinkedList<T>::begin()const{
    return this->head;
}

/*
 * std::shared_ptr<Node<T>> LinkedList<T>::end()const
 * return the pointer to the last element in the list
*/
template<typename T>
std::shared_ptr<Node<T>> LinkedList<T>::end()const{
    return this->tail;
}


#endif//_LIKED_LIST_HPP