#ifndef _NODE_HPP
#define _NODE_HPP

#include <memory>

template<typename T>
struct Node
{
    std::shared_ptr<Node<T>> next_ptr;
    std::shared_ptr<Node<T>> previous_ptr;
    T value;

    Node(T value): next_ptr{nullptr}, previous_ptr{nullptr}, value{value}{
        // std::cout << "Node: " << this << " created" << std::endl;
    }
    ~Node(){
        // std::cout << "Node: " << this << " removed" << std::endl;
    }
};


#endif