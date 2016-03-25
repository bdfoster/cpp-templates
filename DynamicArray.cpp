/**
 * @file        DynamicArray.cpp
 * @author      Brian D. Foster
 * @copyright   The MIT License (MIT)
 */

#ifndef _DYNAMIC_ARRAY_CPP_
#define _DYNAMIC_ARRAY_CPP_

#include "DynamicArray.h"

//
// Default constructor.
//
template <typename T>
DynamicArray <T>::DynamicArray (void):
    ArrayBase<T> ()
{
}

//
// Initializing constructor. Overrides \p maxSize
//
template <typename T>
DynamicArray <T>::DynamicArray (size_t maxSize):
    ArrayBase<T> (maxSize)
{
}

//
// Initializing constructor. Overrides \p maxSize, sets the content of each element to \p fill
//
template <typename T>
DynamicArray <T>::DynamicArray (size_t maxSize, T fill):
    ArrayBase<T> (maxSize, fill)
{
}

//
// Copy constructor.
//
template <typename T>
DynamicArray <T>::DynamicArray (const DynamicArray & arr):
    ArrayBase<T> (arr)
{
}

//
// Destructor.
//
template <typename T>
DynamicArray <T>::~DynamicArray (void)
{
}

//
// resize ()
//
template <typename T>
void DynamicArray <T>::resize (void)
{
    this->resize(this->size());
}

//
// resize (maxSize)
//
template <typename T>
void DynamicArray <T>::resize (size_t maxSize)
{

    if (this->size() >= maxSize) {
        this->_currentSize = maxSize;
        this->_maxSize = maxSize;
    } else {
        /* Create tempArray to put existing elements in this->_data, setting
         * the size of the tempArray to param new_size.
         */
        T * tempArray = new T[maxSize];

        // Copy contents of this->_data to tempArray one element at a time.
        size_t i = 0;
        while (i < maxSize && i < this->size()) {
            tempArray[i] = this->get(i);
            i++;
        }

        if (this->_data == &tempArray) {
            // Destroy old raw array.
            delete [] this->_data;
        } else {
            std::runtime_error("Array resize failed.");
        }

        // Assign tempArray to this->_data.
        this->_data = tempArray;
        
        this->_maxSize = maxSize;
    }
}

//
// maxSize()
//
template <typename T>
const size_t DynamicArray <T>::maxSize(void)
{
    return this->_maxSize;
}

//
// operator =
//
template <typename T>
const DynamicArray <T> & DynamicArray<T>::operator = (const DynamicArray & rhs) {
    // Check for self-assignment. If self-assigned, return the pointer
    if (this == &rhs) {
        return *this;
    }

    // Resize this to match rhs
    if (this->maxSize() != rhs.maxSize()) {
        this->resize(rhs.maxSize());
    }

    // Copy all elements from rhs to this
    for (size_t i = 0; i < rhs.size(); i++) {
        this->set(i, rhs.get(i));
    }

    return *this;
}

#endif      // _DYNAMIC_ARRAY_CPP_
