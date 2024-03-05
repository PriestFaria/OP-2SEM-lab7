#include <iostream>
#include <algorithm>
#include "buff.cpp"
int main() {
    Circ_Buffer<int> circ_buff(3);
    circ_buff.push_back(1223);
    circ_buff.push_back(100); //5 4 909 1223 100
    circ_buff.push_back(10000);
    circ_buff.add(circ_buff.begin() + 1, 108);

    auto p = [](int a, int b){
        return a > b;
    };
    std::sort(circ_buff.begin(), circ_buff.end(), p);

    for(auto i{circ_buff.begin()}; i != circ_buff.end(); ++i){
        std::cout << *i << " ";
    }
    std::cout << "\n";
    for(auto i{circ_buff.begin()}; i != circ_buff.end(); ++i){
        std::cout << *i << " ";
    }
    std::cout << " " << *std::min_element(circ_buff.begin(), circ_buff.end());
    return 0;
}