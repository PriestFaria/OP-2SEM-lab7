

#ifndef LAB7_BUFF_H
#define LAB7_BUFF_H

template<typename T>
class Circ_Buffer {
private:
    unsigned int buff_size;
    unsigned int capacity;
    T *buff;
    T *first;
    T *last;
public:

    class Iterator {
    private:
        T *item;
        unsigned int capacity;
        unsigned int position;
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        Iterator(T *elem, unsigned int capacity, unsigned int position);

        Iterator();

        T &operator*()const;

        Iterator& operator++();

        Iterator& operator--();

        Iterator &operator+=(std::ptrdiff_t c);

        Iterator &operator-=(std::ptrdiff_t c);

        std::ptrdiff_t operator-(const Iterator &iter);

        bool operator==(const Iterator &iter)const;

        bool operator!=(const Iterator &iter)const;

        bool operator>(const Iterator &iter) const;

        bool operator>=(const Iterator &iter) const;

        bool operator<(const Iterator &iter) const;

        bool operator<=(const Iterator &iter) const;

        Iterator operator+(std::ptrdiff_t c) const;

        Iterator operator-(std::ptrdiff_t c) const;

        unsigned int getPosition();
    };

    Circ_Buffer(unsigned int capacity);

    ~Circ_Buffer();

    void pop_front();

    void push_front(const T &elem);

    void pop_back();

    void push_back(const T &elem);

    void change_capacity(unsigned int new_capacity);

    void add(const Iterator &iter);

    void remove(const Iterator &iter);

    Iterator begin() const;

    Iterator end() const;

    Iterator &operator[](unsigned int idx) const;

    unsigned int size();
};

#include "buff.h"

template<typename T>
Circ_Buffer<T>::Circ_Buffer(unsigned int capacity) : capacity(capacity) {
    buff = new T[capacity];
    first = buff;
    last = buff;
    buff_size = 0;
}

template<typename T>
Circ_Buffer<T>::~Circ_Buffer() {
    delete[] buff;
}

template<typename T>
void Circ_Buffer<T>::pop_front() {
    Iterator it_begin = begin();
    Iterator it_end = end();
    if (it_begin == it_end && size() == 0)
        return;

    if (it_begin.getPosition() + 1 >= capacity) {
        first = buff;
    } else {
        first = begin() + 1;
    }

    buff_size--;
}

template<typename T>
void Circ_Buffer<T>::push_front(const T &elem) {
    if (size() == 0) {
        buff[begin().getPosition()] = elem;
        buff_size++;
        return;
    }

    Iterator it_begin = begin();
    Iterator it_end = end();
    if (it_begin == it_end) {
        pop_back();
    }
    buff[(it_begin.getPosition() - 1 + capacity) % capacity] = elem;
    if (begin().getPosition() == 0) {
        first = (buff + capacity - 1);
    } else {
        first--;
    }
    if (it_end.getPosition() == 0) {
        last = (buff + capacity - 1);
    }
    buff_size++;
}

template<typename T>
void Circ_Buffer<T>::pop_back() {
    Iterator it_begin = begin();
    Iterator it_end = end();
    if (it_begin == it_end && size() == 0)
        return;
    if (&(*it_end) == buff + 1) {
        last = buff + capacity - 1;
    } else {
        last--;
    }
    buff_size--;
}

template<typename T>
void Circ_Buffer<T>::push_back(const T &elem) {
    if (size() == 0) {
        pop_front(elem);
        return;
    }
    Iterator it_begin = begin();
    Iterator it_end = end();
    if (it_begin == it_end) {
        pop_front();
    }
    buff[it_end.getPosition()] = elem;

    if (it_end.getPosition() == buff) {
        last = buff + capacity - 1;
    }
    if (it_end.getPosition() == buff) {
        last = buff;
    }
    buff_size++;
}

template<typename T>
void Circ_Buffer<T>::change_capacity(unsigned int new_capacity) {}

template<typename T>
void Circ_Buffer<T>::add(const Circ_Buffer::Iterator &iter) {}

template<typename T>
void Circ_Buffer<T>::remove(const Circ_Buffer::Iterator &iter) {}

template<typename T>
typename Circ_Buffer<T>::Iterator Circ_Buffer<T>::begin() const {
    T *curr = buff;
    for (unsigned int i = 0; i < capacity; curr++, i++) {
        if (curr == first)
            return Circ_Buffer<T>::Iterator(first, capacity, i);
    }
    return Circ_Buffer<T>::Iterator(buff, capacity, 0);
}

template<typename T>
typename Circ_Buffer<T>::Iterator Circ_Buffer<T>::end() const {
    T *curr = buff;
    for (unsigned int i = 0; i < capacity; curr++, i++) {
        if (curr == last) {
            if (i == capacity - 1)
                return Iterator(buff, capacity, 0);
            else
                return Iterator(last + 1, capacity, i);
        }
    }
    return Circ_Buffer<T>::Iterator(buff, capacity, 0);
}

template<typename T>
typename Circ_Buffer<T>::Iterator &Circ_Buffer<T>::operator[](unsigned int idx) const {
    return Circ_Buffer<T>::Iterator(buff[idx], capacity, idx);
}

template<typename T>
unsigned int Circ_Buffer<T>::size() {
    return buff_size;
}

template<typename T>
Circ_Buffer<T>::Iterator::Iterator(T *item, unsigned int capacity, unsigned int position) : item(item),
                                                                                            capacity(capacity),
                                                                                            position(position) {}

template<typename T>
T &Circ_Buffer<T>::Iterator::operator*() const{
    return *item;
}

template<typename T>
typename Circ_Buffer<T>::Iterator& Circ_Buffer<T>::Iterator::operator++() {
    if (position == capacity - 1) {
        item -= capacity + 1;
        position = 0;
    } else {
        item++;
        position++;
    }
    return *this;
}

template<typename T>
typename Circ_Buffer<T>::Iterator& Circ_Buffer<T>::Iterator::operator--() {
    if (position == 0) {
        item += capacity - 1;
        position = capacity - 1;
    } else {
        item--;
        position--;
    }
    return *this;
}


template<typename T>
typename Circ_Buffer<T>::Iterator& Circ_Buffer<T>::Iterator::operator+=(std::ptrdiff_t c) {
    for (unsigned int i = 0; i < c; i++) {
        ++(*this);
    }
    return *this;
}

template<typename T>
typename Circ_Buffer<T>::Iterator& Circ_Buffer<T>::Iterator::operator-=(std::ptrdiff_t c) {
    for (unsigned int i = 0; i < c; i++) {
        --(*this);
    }
    return *this;
}

template<typename T>
std::ptrdiff_t Circ_Buffer<T>::Iterator::operator-(const Circ_Buffer<T>::Iterator &iter) {
    if (position >= iter.position) {
        return position - iter.position;
    } else {
        return capacity + position - iter.position;
    }
}


template<typename T>
bool Circ_Buffer<T>::Iterator::operator==(const Circ_Buffer::Iterator &iter)const {
    return item == iter.item;
}

template<typename T>
bool Circ_Buffer<T>::Iterator::operator!=(const Circ_Buffer::Iterator &iter) const {
    return item != iter.item;
}


template<typename T>
bool Circ_Buffer<T>::Iterator::operator>(const Circ_Buffer::Iterator &iter) const {
    return position > iter.position;
}


template<typename T>
bool Circ_Buffer<T>::Iterator::operator>=(const Circ_Buffer::Iterator &iter) const{
    return position >= iter.position;
}

template<typename T>
bool Circ_Buffer<T>::Iterator::operator<(const Circ_Buffer::Iterator &iter) const{
    return position < iter.position;
}

template<typename T>
bool Circ_Buffer<T>::Iterator::operator<=(const Circ_Buffer::Iterator &iter) const{
    return position <= iter.position;
}

template<typename T>
typename Circ_Buffer<T>::Iterator Circ_Buffer<T>::Iterator::operator+(std::ptrdiff_t c)const {
    Circ_Buffer<T>::Iterator it = Circ_Buffer<T>::Iterator(item, capacity, position);
    for (unsigned int i = 0; i < c; i++) {
        ++it;
    }
    return it;
}

template<typename T>
typename Circ_Buffer<T>::Iterator Circ_Buffer<T>::Iterator::operator-(std::ptrdiff_t c) const{
    Circ_Buffer<T>::Iterator it = Circ_Buffer<T>::Iterator(item, capacity, position);
    for (unsigned int i = 0; i < c; i++) {
        --it;
    }
    return it;
}

template<typename T>
unsigned int Circ_Buffer<T>::Iterator::getPosition() {
    return position;
}

#endif //LAB7_BUFF_H
