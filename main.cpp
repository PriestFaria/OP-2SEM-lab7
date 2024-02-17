#include <iostream>
#include <algorithm>
#include "buff.cpp"
int main() {
    Circ_Buffer<int> circ_buff(3);
    circ_buff.push_front(909);
    circ_buff.push_back(1223);
    circ_buff.push_back(100);
    circ_buff.push_front(4);
    circ_buff.push_front(5);
    circ_buff.pop_front();
    circ_buff.pop_back();
    for(auto i{circ_buff.begin()}; i != circ_buff.end(); ++i){
        std::cout << *i << " ";
    }
//    std::cout << "\n";
//    for(int i = 0; i < 4; i++){
//        std::cout << " " << circ_buff.buff[i] ;
//    }
    std::cout << "\n";
    circ_buff.change_capacity(3);
    for(auto i{circ_buff.begin()}; i != circ_buff.end(); ++i){
        std::cout << *i << " ";
    }
    return 0;
}
