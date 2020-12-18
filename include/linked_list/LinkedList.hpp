#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

#include <memory>

#include "linked_list/Node.hpp"

template<typename T>
class LinkedList{

private:

    std::shared_ptr<Node> head; // the head of the list
    std::shared_ptr<Node> tail; // the tail of the list
    size_t size; // counter for the list size

public:

    LinkedList();
    ~LinkedList() = default;

    // insert methods 
    bool add_first(T value);
    bool add_last(T value);

    // remove methods
    bool remove_first();
    bool remove_last();
    bool remove_val_first(T value);
    bool remove_val_last(T value);

    // display list values
    void display();

};

#endif//_LIKED_LIST_HPP