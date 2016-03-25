/**
 * @file        ArrayBase.h
 * @author      Brian D. Foster
 * @copyright   The MIT License (MIT)
 */

#ifndef _ARRAY_BASE_H_
#define _ARRAY_BASE_H_

#include <cstring>      ///< for size_t definition

/**
 * @class       ArrayBase
 * @brief       Base class for array-like structures.
 * @details     Contains the actual raw array of type T along with common
 *              properties and methods for array like structures.
 * @since       0.1.0
 * @tparam      T       (typename) Element type of array.
 */

template <typename T>
class ArrayBase {
    private:
        /**
         * Raw array of type T.
         * 
         * @since 0.1.0
         */
        T * _data[];
        
        /**
         * Current size of the array.
         * 
         * @since 0.1.0
         */
        size_t _currentSize;
        
        /**
         * Maximum size of the array.
         * 
         * @since 0.1.0
         */
        size_t _maxSize;
        
    public:
        typedef T type;
    
        /**
         * Default initializing constructor.
         * 
         * Creates the raw array of type \p T and sets the maximum size
         * to 10 by default.
         */
        ArrayBase (void);

        /**
         * Initializing constructor. Sets max size to \p maxSize,
         * effectively overriding the default.
         *
         * @param       maxSize     (size_t) Maximum size of the array.
         */
        ArrayBase (size_t maxSize);

        /**
         * Initializing constructor. Sets max size to \p maxSize and
         * filling each element of the array with \p fill.
         *
         * @param       maxSize     (size_t) Maximum size of the array.
         * @param       fill        (T) Contents of each element.
         */
        ArrayBase (size_t maxSize, T fill);

        /**
         * Destructor
         *
         * @since       0.1.0
         */
        ~ArrayBase (void);
        
        /**
         * Query the current size.
         *
         * @return      (size_t) The current size.
         * @since       0.1.0
         */   
        size_t size (void);
        
        /**
         * Query the element at specified index.
         * 
         * @param       index       (size_t) Index of query element.
         * @return      (T) The element at specified index.
         * @throw       std::out_of_range Index is out of the range.
         * @since       0.1.0
         */
        T get (size_t index) const;
        
        /**
         * Sets the element at the specified index.
         * 
         * @param       index       (size_t) Index of element.
         * @param       contents    (T) Contents of element.
         * @return      (void)
         * @throw       std::out_of_range Index is out of the range.
         * @since       0.1.0
         */
        void set (size_t index, T contents);
        
        /**
         * Return first \p index that matches element.
         * 
         * @param       element     (T) Element to match with.
         * @return      (int) \p index or -1 if no match.
         * @since       0.1.0
         */
        int find (T element);
        
        /**
         * Return first \p index that matches \p element starting at
         * the given index.
         * 
         * @param       element     (T) Element to match with.
         * @param       startIndex  (size_t) The \p index to start with.
         * @return      (int) \p index or -1 if no match.
         * @since       0.1.0
         */
        int find (T element, size_t startIndex);
        
        /**
         * Set each element in raw array to given  \p element up to the
         * maximum size.
         *
         * @param       contents    (T) Element to fill ArrayBase with.
         * @return      (void)
         * @since       0.1.0
         */
        void fill (T contents);
        
        /**
         * Clears all elements from the array.
         * @return      (void)
         * @since       0.1.0
         */
        void clear ();
        
        /**
         * Test to see if array is empty.
         * 
         * @return      (void)
         * @since       0.1.0
         */
        bool virtual isEmpty ();
        
        /**
         * Determine equality with given ArrayBase.
         * 
         * @param       rhs         (const ArrayBase <T> &) ArrayBase to
         *                          test against.
         * @return      (bool) True if equal, otherwise false.
         * @since       0.1.0
         */
        bool operator == (const ArrayBase <T> & rhs) const;
        
        /**
         * Determine inequality with given ArrayBase.
         * 
         * @param       rhs         (const ArrayBase <T> &) ArrayBase to
         *                          test against.
         * @return      (bool) True if inequal, otherwise false.
         * @since       0.1.0
         */
        bool operator != (const ArrayBase <T> & rhs) const;
        
        /**
         * Query the element given the index.
         * @param       index       (size_t) Index of the element.
         * @return      (T const) element at specified \p index.
         * @since       0.1.0
         */
        T operator [] (size_t index) const;
        
        /**
         * Query the element given the index.
         *
         * @param       index       (size_t) Index of the element.
         * @return      (T &) element at specified \p index.
         * @since       0.1.0
         */
        T & operator [] (size_t index);
};

#include "ArrayBase.cpp"

#endif  // _ARRAY_BASE_H_
