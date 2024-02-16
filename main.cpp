#include <iostream>
#include "buff.h"

int main() {
    Circ_Buffer<int> circ_buff(10);
    for (int i = 0; i < 10; i++) {
        std::cout << "\n==================ИТЕРАЦИЯ " << i << " ==================================\n";
        circ_buff.push_front(i);
        for (auto iter{circ_buff.begin()}; iter != circ_buff.end(); ++iter)
            std::cout << *iter << " ";
    }

    std::sort(circ_buff.begin(), circ_buff.end());
    std::cout << "\n";
    for (auto iter{circ_buff.begin()}; iter != circ_buff.end(); ++iter)
        std::cout << *iter << " ";

    return 0;
}

