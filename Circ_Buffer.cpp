//template<typename T>
//Circ_Buffer<T>::Circ_Buffer(unsigned int capacity) : capacity(capacity) {
//    buff = new T[capacity];
//    first = buff;
//    last = buff;
//    buff_size = 0;
//}
//
//template<typename T>
//Circ_Buffer<T>::~Circ_Buffer() {
//    delete[] buff;
//}
//
//template<typename T>
//void Circ_Buffer<T>::pop_front() {
//    Iterator it_begin = begin();
//    Iterator it_end = end();
//    if (it_begin == it_end && size() == 0)
//        return;
//
//    if (it_begin.getPosition() + 1 >= capacity) {
//        first = buff;
//    } else {
//        first = begin() + 1;
//    }
//
//    buff_size--;
//}
//
//template<typename T>
//void Circ_Buffer<T>::push_front(const T &elem) {
//    if (size() == 0) {
//        buff[begin().getPosition()] = elem;
//        return;
//    }
//
//    Iterator it_begin = begin();
//    Iterator it_end = end();
//    if (it_begin == it_end) {
//        pop_back();
//    }
//    buff[(it_begin.getPosition() - 1 + capacity) % capacity] = elem;
//    if (begin().getPosition() == 0) {
//        first = (buff + capacity - 1);
//    } else {
//        first--;
//    }
//    if (it_end.getPosition() == 0) {
//        last = (buff + capacity - 1);
//    }
//    buff_size++;
//}
//
//template<typename T>
//void Circ_Buffer<T>::pop_back() {
//    Iterator it_begin = begin();
//    Iterator it_end = end();
//    if (it_begin == it_end && size() == 0)
//        return;
//    if (&(*it_end) == buff + 1) {
//        last = buff[capacity - 1];
//    } else {
//        last--;
//    }
//    buff_size--;
//}
//
//template<typename T>
//void Circ_Buffer<T>::push_back(const T &elem) {
//    if (size() == 0) {
//        pop_front(elem);
//        return;
//    }
//    Iterator it_begin = begin();
//    Iterator it_end = end();
//    if (it_begin == it_end) {
//        pop_front();
//    }
//    buff[it_end.getPosition()] = elem;
//
//    if (it_end.getPosition() == buff) {
//        last = buff + capacity - 1;
//    }
//    if (it_end.getPosition() == buff) {
//        last = buff;
//    }
//    buff_size++;
//}
//
//template<typename T>
//void Circ_Buffer<T>::change_capacity(unsigned int new_capacity) {}
//
//template<typename T>
//void Circ_Buffer<T>::add(const Circ_Buffer::Iterator &iter) {}
//
//template<typename T>
//void Circ_Buffer<T>::remove(const Circ_Buffer::Iterator &iter) {}
//
//template<typename T>
//typename Circ_Buffer<T>::Iterator &Circ_Buffer<T>::begin() const {
//    T *curr = buff;
//    for (unsigned int i = 0; i < capacity; curr++, i++) {
//        if (curr == first)
//            return Iterator(first, capacity, i);
//    }
//
//}
//
//template<typename T>
//typename Circ_Buffer<T>::Iterator &Circ_Buffer<T>::end() const {
//    T *curr = buff;
//    for (unsigned int i = 0; i < capacity; curr++, i++) {
//        if (curr == last) {
//            if (i == capacity - 1)
//                return Iterator(buff, capacity, 0);
//            else
//                return Iterator(last + 1, capacity, i);
//        }
//    }
//}
//
//template<typename T>
//typename Circ_Buffer<T>::Iterator &Circ_Buffer<T>::operator[](unsigned int idx) const {
//    return Circ_Buffer<T>::Iterator(buff[idx], capacity, idx);
//}
//
//template<typename T>
//unsigned int Circ_Buffer<T>::size() {
//    return buff_size;
//}