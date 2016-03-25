/**
 * @file        ArrayBase.cpp
 * @author      Brian D. Foster
 * @copyright   The MIT License (MIT)
 */

#ifndef _ARRAY_BASE_CPP_
#define _ARRAY_BASE_CPP_

#include "ArrayBase.h"
#include <stdexcept>        ///< for std::out_of_bounds exception

//
// Default constructor.
//
template <typename T>
ArrayBase <T>::ArrayBase (void):
    _data (new T[10]),
    _currentSize (0),
    _maxSize (10) { }

//
// Initializing constructor. Overrides \p _maxSize
//
template <typename T>
ArrayBase <T>::ArrayBase (size_t maxSize):
    _data (nullptr),
    _currentSize (0),
    _maxSize (0)
{
    if (maxSize > 0) {
        this->_maxSize = maxSize;
    } else {
        this->_maxSize = 10;
    }
    
    this->_data = new T[this->_maxSize];
}

//
// Initializing constructor. Overrides \p _maxSize and sets the context of each element to \p fill.
//
template <typename T>
ArrayBase <T>::ArrayBase (size_t maxSize, T fill):
    _data (nullptr),
    _currentSize (0),
    _maxSize (0)
{
    if (maxSize > 0) {
        this->_maxSize = maxSize;
    } else {
        this->_maxSize = 10;
    }

    this->_data = new T[this->_maxSize];

    this->fill(fill);
}

//
// Destructor.
//
template <typename T>
ArrayBase <T>::~ArrayBase (void)
{
    // Only delete if this->_data isn't a nullptr.
    if (nullptr != this->_data) {
        delete [] this->_data;
    }
}

//
// get (index)
//
template <typename T>
T ArrayBase <T>::get (size_t index) const
{
    /* Check to make sure the index is within range of _currentSize.
     * If not, throw std::out_of_range.
     */
    if (index >= this->_currentSize) {
        // Index is out of range
        throw std::out_of_range("Invalid index value.");
    }

    return this->_data[index];
}

//
// set (index, contents)
//
template <typename T>
void ArrayBase <T>::set (size_t index, T contents)
{
    /* Check to make sure index is within range of _currentSize
     * If not, throw std::out_of_range exception.
     */
    if (index >= this->_currentSize) {
        // Index is out of range
        throw std::out_of_range("Invalid index value.");
    }

    this->_data[index] = contents;

    // If index equals this->_currentSize, increment by one
    if (index == this->_currentSize) {
        this->_currentSize++;
    }
}

//
// find (element)
//
template <typename T>
int ArrayBase <T>::find (T element)
{
    return this->find(element, 0);
}

//
// find (element, startIndex)
//
template <typename T>
int ArrayBase <T>::find (T element, size_t startIndex)
{
    /* Check to make sure index is within range.
     * If not, throw std::out_of_range exception.
     */
    if (startIndex >= this->_currentSize) {
        // index is out of range
        throw std::out_of_range("Invalid index value");
    }

    int returnIndex = -1;

    /*
     * While returnIndex equals -1 and start is less than 
     * _currentSize, keep going.
     */
    while (returnIndex == -1 && startIndex < this->_currentSize) {
        // Check to see if data at current startIndex equals element.
        if (this->_data[startIndex] == element) {
            // Match, set startIndex as returnIndex, loop completes.
            returnIndex == startIndex;
        } else {
            // No match, increment startIndex
            startIndex++;
        }
    }

    return returnIndex;
}

//
// fill(element)
//
template <typename T>
void ArrayBase <T>::fill (T contents)
{
    // For each element in the array, assign to contents.
    for (size_t i = 0; i < this->_maxSize; i++) {
        this->_data[i] = contents;
    }

    this->_currentSize = this->_maxSize;
}

//
// operator ==
//
template <typename T>
bool ArrayBase <T>::operator == (const ArrayBase & rhs) const
{
    /* Check to see the number of elements in each. If they don't match,
     * we know they are not equal.
     */
    if (this->_currentSize != rhs._currentSize) {
        return false;
    }

    /* Check elements in each raw array at the same index for all 
     * indexes. The first two elements that don't match, return false.
     */
    for (size_t i = 0; i < this->_currentSize; i++) {
        if (this->_data[i] != rhs._data[i]) {
            return false;
        }
    }

    return true;
}

//
// operator !=
//
template <typename T>
bool ArrayBase <T>::operator != (const ArrayBase & rhs) const
{
    if (this == rhs) {
        return false;
    }

    return true;
}

//
// operator []
//
template <typename T>
T & ArrayBase <T>::operator [] (size_t index)
{
	// Shortcut to this->get()
	return this->get(index);
}

//
// operator []
//
template <typename T>
T ArrayBase <T>::operator [] (size_t index) const
{
	// Shortcut to this->get()
	return this->get(index);
}

#endif      // _ARRAY_BASE_CPP_
