#ifndef _NODE_HPP
#define _NODE_HPP

#include <memory>

template<typename T>
struct Node
{
    std::shared_ptr<Node> next_ptr;
    std::shared_ptr<Node>previous_pre;
    T value;
};


#endif