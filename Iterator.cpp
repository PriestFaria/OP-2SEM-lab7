//#include "buff.h"
//
//template<typename T>
//Circ_Buffer<T>::Iterator::Iterator(T *item, unsigned int capacity, unsigned int position) : item(item),
//                                                                                            capacity(capacity),
//                                                                                            position(position) {}
//
//template<typename T>
//T &Circ_Buffer<T>::Iterator::operator*() {
//    return *item;
//}
//
//template<typename T>
//void Circ_Buffer<T>::Iterator::operator++() {
//    if (position == capacity - 1) {
//        item -= capacity + 1;
//        position = 0;
//    } else {
//        item++;
//        position++;
//    }
//}
//
//template<typename T>
//void Circ_Buffer<T>::Iterator::operator--() {
//    if (position == 0) {
//        item += capacity - 1;
//        position = capacity - 1;
//    } else {
//        item--;
//        position--;
//    }
//}
//
//
//template<typename T>
//void Circ_Buffer<T>::Iterator::operator+=(unsigned int c) {
//    for (unsigned int i = 0; i < c; i++) {
//        (*this)++;
//    }
//}
//
//template<typename T>
//void Circ_Buffer<T>::Iterator::operator-=(unsigned int c) {
//    for (unsigned int i = 0; i < c; i++) {
//        (*this)--;
//    }
//}
//
//template<typename T>
//int Circ_Buffer<T>::Iterator::operator-(const Circ_Buffer::Iterator &iter) {
//    int diff = iter.position - position;
//    return (diff >= 0) ? diff : (capacity + diff);
//}
//
//
//template<typename T>
//bool Circ_Buffer<T>::Iterator::operator==(const Circ_Buffer::Iterator &iter) {
//    return item == iter.item;
//}
//
//template<typename T>
//bool Circ_Buffer<T>::Iterator::operator!=(const Circ_Buffer::Iterator &iter) {
//    return item != iter.item;
//}
//
//
//template<typename T>
//bool Circ_Buffer<T>::Iterator::operator>(const Circ_Buffer::Iterator &iter) {
//    return position > iter.position;
//}
//
//
//template<typename T>
//bool Circ_Buffer<T>::Iterator::operator>=(const Circ_Buffer::Iterator &iter) {
//    return position >= iter.position;
//}
//
//template<typename T>
//bool Circ_Buffer<T>::Iterator::operator<(const Circ_Buffer::Iterator &iter) {
//    return position < iter.position;
//}
//
//template<typename T>
//bool Circ_Buffer<T>::Iterator::operator<=(const Circ_Buffer::Iterator &iter) {
//    return position <= iter.position;
//}
//
//template<typename T>
//typename Circ_Buffer<T>::Iterator Circ_Buffer<T>::Iterator::operator+(const unsigned int c) {
//    Circ_Buffer<T>::Iterator it = Circ_Buffer<T>::Iterator(item, capacity, position);
//    for(unsigned int i = 0; i < c; i++){
//        it++;
//    }
//    return it;
//}
//
//template<typename T>
//typename Circ_Buffer<T>::Iterator Circ_Buffer<T>::Iterator::operator-(const unsigned int c) {
//    Circ_Buffer<T>::Iterator it = Circ_Buffer<T>::Iterator(item, capacity, position);
//    for(unsigned int i = 0; i < c; i++){
//        it--;
//    }
//    return it;
//}
//
//template<typename T>
//unsigned int Circ_Buffer<T>::Iterator::getPosition() {
//    return position;
//}