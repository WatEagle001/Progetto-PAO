#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>
#include "Model/outofboundsexception.h"
#include "Model/emptyexception.h"

template <class T> class Array;
template <class T> std::ostream& operator<< (std::ostream&, const Array<T>&);


template <class T>
class Array { // array implementato come se fosse un vector
    friend std::ostream& operator<< <T>(std::ostream&, const Array<T>&);
private:
    T* _content;
    int _size;
    int _capacity;
    static T* copia(T* t, int sz, int cap);
public:
    Array(const T& t = T(), int k = 0);
    Array(const Array& t);
    Array& operator=(const Array& t);
    ~Array();
    bool operator==(const Array& a) const;
    int size() const;
    int capacity() const;
    bool empty() const;
    bool full() const;
    void resize();

    class iterator {
        friend class Array<T>;
    private:
        T* i;
        bool pte;
        iterator(T* e, bool past = false);
    public:
        iterator();
        iterator& operator=(iterator it);
        T& operator*() const;
        T* operator->() const;
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
        iterator operator+(int n) const;
        iterator operator-(int n) const;
        iterator& operator+=(int n);
        iterator& operator-=(int n);
        T& operator[](int n) const;
        bool operator<(iterator it) const;
        bool operator>(iterator it) const;
        bool operator<=(iterator it) const;
        bool operator>=(iterator it) const;
        bool operator==(iterator it) const;
        bool operator!=(iterator it) const;
    };

    iterator begin() const;
    iterator end() const;
    T& operator[] (int pos);
    const T& operator[] (int pos) const;
    T& operator[] (Array::iterator pos) const;
    void push_back(const T& t);
    void pop_back();
    T erase(iterator pos);
    void clear();
};

template <class T>
std::ostream& operator<< (std::ostream& os, const Array<T>& a) {
    for (typename Array<T>::const_iterator it = a.cbegin(); it != a.cend(); it++) {
        os << *it << " ";
    }
    return os;
}


template<class T>
T* Array<T>::copia(T *t, int sz, int cap) {
    T* a = new T[cap];
    for (int i = 0; i < sz; ++i)
        a[i] = t[i];
    return a;
}

template<class T>
Array<T>::Array(const T& t, int k) : _content(k == 0 ? nullptr : new T[k * 2]), _size(k), _capacity(k * 2) {
    for (int i = 0; i < _size; i++)
        _content[i] = t;
}

template<class T>
Array<T>::Array(const Array& t): _content(copia(t._content, t._size, t._capacity)), _size(t._size), _capacity(t._capacity) {}

template<class T>
Array<T>& Array<T>::operator=(const Array& t) {
    if (this != &t) {
        delete[] _content;
        _content = copia(t, t._size, t._capacity);
        _size = t._size;
        _capacity = t._capacity;
    }
    return *this;
}

template<class T>
Array<T>::~Array() {
    delete[] _content;
}

template<class T>
bool Array<T>::operator==(const Array &a) const {
    if (this == &a) return true;
    if (_size != a._size) return false;
    for (int i = 0; i < _size; i++)
        if (_content[i] != a[i])
            return false;
    return true;
}

template<class T>
int Array<T>::size() const {
    return _size;
}

template<class T>
int Array<T>::capacity() const {
    return _capacity;
}

template<class T>
bool Array<T>::empty() const {
    return _size == 0;
}

template<class T>
bool Array<T>::full() const {
    return _size == _capacity;
}

template<class T>
void Array<T>::resize() {
    if (_capacity == 0) ++_capacity;
    _content = copia(_content, _size, _capacity * 2);
    _capacity = _capacity * 2;
}

template<class T>
Array<T>::iterator::iterator(T *e, bool pte): i(e), pte(pte) {}

template<class T>
Array<T>::iterator::iterator(): i(nullptr), pte(false) {}

template<class T>
typename Array<T>::iterator& Array<T>::iterator::operator=(Array::iterator it) {
    i = it.i;
    return *this;
}


template<class T>
T& Array<T>::iterator::operator[](int n) const {
    if (i + n * sizeof (T) == nullptr){
        throw OutOfBoundsException();
    }
    return *i;
}

template<class T>
T& Array<T>::iterator::operator*() const {
    return *i;
}

template<class T>
T* Array<T>::iterator::operator->() const {
    return i;
}

template<class T>
typename Array<T>::iterator& Array<T>::iterator::operator++() {
    if (i) {
        if (!pte) {
            if (i + sizeof(T) == nullptr) {++i; pte = true;}
            else ++i;
        }
    }
    return *this;
}

template<class T>
typename Array<T>::iterator Array<T>::iterator::operator++(int) {
    iterator aux = i;
    i++;
    return aux;
}

template<class T>
typename Array<T>::iterator& Array<T>::iterator::operator--() {
    if (i) {
        if (pte){
            i--;
            pte = false;
        }
        else i--;
    }
    return *this;
}

template<class T>
typename Array<T>::iterator Array<T>::iterator::operator--(int) {
    iterator aux = i;
    i--;
    return aux;
}

template<class T>
typename Array<T>::iterator Array<T>::iterator::operator+(int n) const {
    iterator aux = i;
    if (aux.i) {
        if (!aux.pte) {
            if (i + n * sizeof (T) == nullptr) {
                aux.i += n;
                aux.pte = true;
            }
            else{
                aux.i += n;
            }
        }
    }
    return aux;
}

template<class T>
typename Array<T>::iterator Array<T>::iterator::operator-(int n) const {
    iterator aux = i;
    if (aux.i) {
        if (aux.pte) {
            aux.i -= n;
            aux.pte = false;
        }
        else aux.i -= n;
    }
    return aux;
}


template<class T>
typename Array<T>::iterator& Array<T>::iterator::operator+=(int n) {
    if (i) {
        if (!pte) {
            if (i + n * sizeof (T) == nullptr) {
                i += n;
                pte = true;
            }
            else i += n;
        }
    }
    return *this;
}

template<class T>
typename Array<T>::iterator& Array<T>::iterator::operator-=(int n) {
    if (i) {
        if (pte){
            i -= n;
            pte = false;
        }
        else i -= n;
    }
    return *this;
}

template<class T>
bool Array<T>::iterator::operator<(Array::iterator it) const {
    return i < it.i;
}

template<class T>
bool Array<T>::iterator::operator>(Array::iterator it) const {
    return i > it.i;
}

template<class T>
bool Array<T>::iterator::operator<=(Array::iterator it) const {
    return i <= it.i;
}

template<class T>
bool Array<T>::iterator::operator>=(Array::iterator it) const {
    return i >= it.i;
}

template<class T>
bool Array<T>::iterator::operator==(Array::iterator it) const {
    return i == it.i;
}

template<class T>
bool Array<T>::iterator::operator!=(Array::iterator it) const {
    return i != it.i;
}

template<class T>
T& Array<T>::operator[](Array::iterator pos) const {
    return *(pos.i);
}

template<class T>
const T& Array<T>::operator[](int pos) const {
    if (pos < 0 || pos >= _size){
        throw OutOfBoundsException();
    }
    return _content[pos];
}

template<class T>
typename Array<T>::iterator Array<T>::begin() const {
    if (empty()){
        return nullptr;
    }
    return &_content[0];
}

template<class T>
typename Array<T>::iterator Array<T>::end() const {
    if (empty() == true){
        return nullptr;
    }
    return iterator(&_content[_size], true);
}


template<class T>
T& Array<T>::operator[](int pos) {
    if (pos < 0 || pos >= _size){
        throw OutOfBoundsException();
    }
    return _content[pos];
}

template<class T>
void Array<T>::push_back(const T &t) {
    if (full() == true){
        resize();
    }
    _content[_size] = t;
    _size++;
}

template<class T>
void Array<T>::pop_back() {
    if (!empty()) {
        _content[_size - 1] = _content[_size];
        _size--;
    } else{
        throw new EmptyException();
    }
}

template<class T>
T Array<T>::erase(Array::iterator pos) {
    T aux = *pos;
    for (; pos != end(); pos++) {
        *pos = *(pos + 1);
    }
    _size--;
    return aux;
}

template<class T>
void Array<T>::clear() {
    delete[] _content;
    _content = new T[_capacity];
    _size = 0;
}

#endif  // ARRAY_H
