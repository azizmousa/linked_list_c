#ifndef _NODE_HPP
#define _NODE_HPP

#include <memory>

template<typename T>
struct Node
{
    std::shared_ptr<Node<T>> next_ptr;
    std::shared_ptr<Node<T>>previous_pre;
    T value;
};


#endif