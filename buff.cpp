
#include "iterator"

template<typename T>
class Circ_Buffer {
private:
    unsigned int buff_size;
    unsigned int capacity;
    unsigned int first;
    unsigned int last;
public:

    T *buff;

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

        Iterator(T *item, unsigned int capacity, unsigned int position) : item(item), capacity(capacity),
                                                                          position(position) {

        };

        bool operator>=(const Iterator &iter) const {
            return *item >= *iter;
        }

        bool operator>(const Iterator &iter) const {
            return *item > *iter;
        }

        bool operator<=(const Iterator &iter) const {
            return *item <= *iter;
        }

        bool operator<(const Iterator &iter) const {
            return *item < *iter;
        }

        bool operator!=(const Iterator &iter) const {
            return *item != *iter;
        };

        bool operator==(const Iterator &iter) const {
            return *item == *iter;
        };

        T &operator*() const {
            return *item;
        };

        Iterator &operator++() {
            if (position > capacity)
                return *this;
            else {
                item += 1;
                position++;
                return *this;
            }
        };

        unsigned int getPosition() {
            return position;
        }

        Iterator &operator--() {
            if (position == 0) {
                return *this;
            } else {
                position--;
                item--;
                return *this;
            }
        }

        Iterator &operator+=(std::ptrdiff_t c) {
            for (unsigned int i = 0; i < c; i++) {
                ++(*this);
            }
            return *this;
        }

        T &operator[](std::ptrdiff_t offset) const {
            return *(item + offset);
        }

        Iterator &operator-=(std::ptrdiff_t c) {
            for (unsigned int i = 0; i < c; i++) {
                --(*this);
            }
            return *this;
        }

        std::ptrdiff_t operator-(const Iterator &iter) const {
            return std::ptrdiff_t(position) - std::ptrdiff_t(iter.position);
        }

        Iterator operator+(std::ptrdiff_t c) const {
            if (position + c < capacity)
                return Iterator(item + c, capacity, position + c);
            else
                return Iterator(item + capacity - 1, capacity, capacity - 1);
        }

        Iterator operator-(std::ptrdiff_t c) const {
            if (position - c < 0) {
                return Iterator(item - position, capacity, 0);
            } else {
                return Iterator(item - c, capacity, position - c);
            }
        }

        Iterator &operator=(T &newValue) {
            *item = newValue;
            return *this;
        }

    };

    Circ_Buffer(unsigned int capacity) : capacity(capacity) {
        buff = new T[capacity + 1];
        first = 0;
        last = 0;
        buff_size = 0;
    };

    ~Circ_Buffer() {
        delete[] buff;
    };

    void pop_front() {
        if (buff_size == 0) {
            return;
        }
        buff_size--;
        first++;
        for (unsigned int i = first; i <= last; i++) {
            buff[i - 1] = buff[i];
        }
        first--;
        last--;
    };

    void push_front(const T &elem) {
        if (buff_size >= capacity) {
            for (unsigned int i = last - 1; i > first; i--) {
                buff[i + 1] = buff[i];
            }
            buff[first + 1] = buff[first];
        } else {
            for (unsigned int i = last; i > first; i--) {
                buff[i + 1] = buff[i];
            }
            buff[first + 1] = buff[first];
            buff_size++;
            if (last != capacity) {
                last++;
            }
        }
        buff[first] = elem;
    };

    void pop_back() {
        if (buff_size == 0) {
            return;
        }
        buff_size--;
        last--;
    };

    void push_back(const T &elem) {
        if (buff_size >= capacity) {
            for (unsigned int i = first + 1; i <= last; i++) {
                buff[i - 1] = buff[i];
            }
            buff[last] = elem;
        } else {
            buff[last] = elem;
            buff_size++;

            if (last != capacity) {
                last++;
            }
        }
    };

    void change_capacity(unsigned int new_capacity) {
        T *newBuff = new T[new_capacity + 1];
        for (unsigned int i = 0; i < new_capacity; i++) {
            newBuff[i] = buff[i];
        }
        if (buff_size > new_capacity) {
            last = new_capacity - 1;
        }
        delete[] buff;
        buff = newBuff;
        capacity = new_capacity;
    };

    void add(Iterator iter, T value) {
        if (iter == end()) return;
        if (buff_size >= capacity) {
            for (unsigned int i = last - 1; i > iter.getPosition(); i--) {
                buff[i + 1] = buff[i];
            }
            buff[iter.getPosition() + 1] = buff[iter.getPosition()];
        } else {
            for (unsigned int i = last; i > iter.getPosition(); i--) {
                buff[i + 1] = buff[i];
            }
            buff[iter.getPosition() + 1] = buff[iter.getPosition()];
            buff_size++;
            if (last != capacity) {
                last++;
            }
        }
        buff[iter.getPosition()] = value;
    };

    void remove(Iterator iter){
        if(iter.getPosition()>=last+1)
            return;
        if (buff_size == 0) {
            return;
        }
        if(iter == begin()){
            pop_front();
        }else{
            buff_size--;
            for (unsigned int i = iter.getPosition() + 1; i <= last; i++) {
                buff[i - 1] = buff[i];
            }
            last--;
        }

    };

    Iterator begin() const {
        return Iterator(buff, capacity, 0);
    };

    Iterator end() const {
        return Iterator(buff + last, capacity, last);
    }

    T &operator[](unsigned int idx) const {
        return buff[idx];
    };

    T &getFirst() {
        return buff[first];
    }

    T &getLast() {
        return buff[last];
    }

    unsigned int size() {
        return buff_size;
    };

};

