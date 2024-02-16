#include <iostream>
#include "buff.h"

int main() {
    Circ_Buffer<int> circ_buff(11);
    circ_buff.push_front(2);
    circ_buff.push_front(4);
    circ_buff.push_front(3);
    circ_buff.push_front(12);
    circ_buff.push_front(22);
    circ_buff.push_front(6);
    circ_buff.push_front(64);
    circ_buff.push_front(2);
    circ_buff.push_front(64);
    circ_buff.push_front(1);
    circ_buff.push_front(-123);

    std::cout << "Original sequence: ";
    for (auto iter{circ_buff.begin()}; iter != circ_buff.end(); ++iter)
        std::cout << *iter << " ";

    std::cout << "\n\nBefore sorting with std::sort: ";
    for (auto iter{circ_buff.begin()}; iter != circ_buff.end(); ++iter)
        std::cout << *iter << " ";

    std::sort(circ_buff.begin(), circ_buff.end());

    std::cout << "\n\nAfter sorting with std::sort: ";
    for (auto iter{circ_buff.begin()}; iter != circ_buff.end(); ++iter)
        std::cout << *iter << " ";

    Circ_Buffer<int>::Iterator a = std::find(circ_buff.begin(), circ_buff.end(), 64);
    ++a;
    ++a;
    ++a;
    ++a;

    return 0;
}
//нужно всегда выделять одну свободную ячейку