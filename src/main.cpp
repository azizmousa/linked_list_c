#include <iostream>
#include <vector>

#include "linked_list/LinkedList.hpp"
int main(int argc, char *argv[]){

    LinkedList<int> ls;
    ls.add_first(10);
    ls.add_first(30);
    ls.add_first(40);
    ls.add_first(50);
    ls.display();
    ls.add_last(90);
    ls.add_last(80);
    ls.display();
    ls.remove_first();
    ls.display();
    ls.remove_last();
    ls.display();
    ls.remove(30, false);
    ls.display();
    std::cout << ls.get_size() << std::endl;
    std::cout << ls.find(10)->value << std::endl;
    LinkedList<int>::NodePointer first = ls.begin();
    LinkedList<int>::NodePointer last = ls.end();
    std::cout << "First: " << first->value << std::endl;
    std::cout << "Last: " << last->value << std::endl;
    for(auto i{ls.begin()}; i != ls.end()->next_ptr; i=i->next_ptr){
        std::cout << i->value << std::endl;
    }
    return 0;
}