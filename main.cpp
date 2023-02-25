#include <iostream>
#include "DoubleLinkedList.h"

int main()
{
    DoubleLinkedList list;
    list.insert(5);
    list.insert(0);
    list.insert(99);
    list.insert(7);
    list.insert(-14);
    list.print();
    list.backprint();

    list.remove(7);
    list.remove(-14);
    list.remove(99);
    list.remove(9);
    list.print();
    list.backprint();
}
