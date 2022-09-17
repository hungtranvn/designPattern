/*
 * iterator.cpp
 */
#include <algorithm>
#include <array>
#include <iostream>
#include <list>
#include <vector>

// Custom data structure with iterators
// For some additional implementations for Vector
// https://leimao.github.io/blog/CPP-Const-Overloading/
template <typename T>
class DummyVector
{
public:
    // Default constructors
    DummyVector();
    // Constructors which take more than zero arguments
    explicit DummyVector(size_t size);
    explicit DummyVector(std::initializer_list<T> lst);

    // Iterator basics
    class Iterator;
    Iterator begin();
    Iterator end();

private:
    size_t mSize;
    T* mBuffer;
};

// However, the best practice for template classes and functions is to put the
// definition and the declaration together. Mainly, there are two reasons
// 1. Compiler needs to know all the definition for any templates during compile
// time
// 2. Namescope is trivial to write and confusing
template <typename T>
DummyVector<T>::DummyVector() : mSize{0}, mBuffer{nullptr}
{
}

template <typename T>
DummyVector<T>::DummyVector(size_t size) : mSize{size}, mBuffer{new T[size]}
{
    for (int i = 0; i < mSize; i++)
    {
        mBuffer[i] = 0;
    }
}

template <typename T>
DummyVector<T>::DummyVector(std::initializer_list<T> lst)
    : mSize{lst.size()}, mBuffer{new T[lst.size()]}
{
    std::copy(lst.begin(), lst.end(), this->mBuffer);
}

// Iterator is an abstract notion
template <typename T>
class DummyVector<T>::Iterator
{
public:
    // Constructor
    Iterator(T* ptr);
    // Compulsory methods
    // Prefix
    Iterator& operator++();
    Iterator& operator--();
    // Postfix
    // Returns the value before update
    // Impossible to return by reference
    // Return by value instead
    Iterator operator++(int);
    Iterator operator--(int);
    T& operator*();
    bool operator==(const Iterator& iter);
    bool operator!=(const Iterator& iter);

private:
    T* mPtr;
};

template <typename T>
DummyVector<T>::Iterator::Iterator(T* ptr) : mPtr{ptr}
{
}

// Prefix overloading
// If T::X is a dependent typename, then we need to prefix it by typename to
// tell the compiler to parse it in a certain way.
template <typename T>
typename DummyVector<T>::Iterator& DummyVector<T>::Iterator::operator++()
{
    this->mPtr++;
    return *this;
}
// Prefix overloading
template <typename T>
typename DummyVector<T>::Iterator& DummyVector<T>::Iterator::operator--()
{
    this->mPtr--;
    return *this;
}

// Postfix overloading
template <typename T>
typename DummyVector<T>::Iterator DummyVector<T>::Iterator::operator++(int)
{
    DummyVector<T>::Iterator temp = *this;
    this->mPtr++;
    return temp;
}
// Postfix overloading
template <typename T>
typename DummyVector<T>::Iterator DummyVector<T>::Iterator::operator--(int)
{
    DummyVector<T>::Iterator temp = *this;
    this->mPtr--;
    return temp;
}

template <typename T>
T& DummyVector<T>::Iterator::operator*()
{
    return *this->mPtr;
}

template <typename T>
bool DummyVector<T>::Iterator::operator==(const Iterator& iter)
{
    return this->mPtr == iter.mPtr;
}

template <typename T>
bool DummyVector<T>::Iterator::operator!=(const Iterator& iter)
{
    return this->mPtr != iter.mPtr;
}

template <typename T>
typename DummyVector<T>::Iterator DummyVector<T>::begin()
{
    return DummyVector<T>::Iterator{this->mBuffer};
}

template <typename T>
typename DummyVector<T>::Iterator DummyVector<T>::end()
{
    return DummyVector<T>::Iterator{this->mBuffer + this->mSize};
}

// Template function for iterators
template <typename Iter>
Iter maximum(Iter first, Iter last)
{
    Iter max = first;
    for (Iter iter = first; iter != last; iter++)
    {
        if (*max < *iter)
        {
            max = iter;
        }
    }
    return max;
}

int main()
{
    // STL containers
    std::list<int> lst{1, 2, 3, 4, 5};
    std::array<float, 5> arr{1, 2, 3, 4, 5};
    std::vector<float> vec{1, 2, 3, 4, 5};
    // Custom container
    DummyVector<double> dummyVec{1, 2, 3, 4, 5};

    auto lstMaxIter = maximum(lst.begin(), lst.end());
    std::cout << *lstMaxIter << std::endl;
    auto arrMaxIter = maximum(arr.begin(), arr.end());
    std::cout << *arrMaxIter << std::endl;
    auto vecMaxIter = maximum(vec.begin(), vec.end());
    std::cout << *vecMaxIter << std::endl;
    auto dummyVecMaxIter = maximum(dummyVec.begin(), dummyVec.end());
    std::cout << *dummyVecMaxIter << std::endl;

    lstMaxIter = std::max_element(lst.begin(), lst.end());
    std::cout << *lstMaxIter << std::endl;
    arrMaxIter = std::max_element(arr.begin(), arr.end());
    std::cout << *arrMaxIter << std::endl;
    vecMaxIter = std::max_element(vec.begin(), vec.end());
    std::cout << *vecMaxIter << std::endl;
    dummyVecMaxIter = std::max_element(dummyVec.begin(), dummyVec.end());
    std::cout << *dummyVecMaxIter << std::endl;
}
