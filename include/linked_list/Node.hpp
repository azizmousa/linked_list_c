#ifndef _NODE_HPP
#define _NODE_HPP

template<typename T>
struct Node
{
    Node *next_ptr;
    Node *previous_pre;
    T value;
};


#endif