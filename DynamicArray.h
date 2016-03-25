/**
 * @file        DynamicArray.h
 * @author      Brian D. Foster
 * @copyright   The MIT License (MIT)
 */

#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

#include "ArrayBase.h"

/**
 * @class       DynamicArray
 * @brief       A resizable array. Inherits ArrayBase.
 * @details     Contains specific methods to resize a raw array.
 * @since       0.1.0
 * @tparam      T       (typename) Element type of array.
 */
template <typename T>
class DynamicArray : public ArrayBase <T> {

    public:
        /**
         * Default initializing constructor.
         *
         * Calls ArrayBase default initializing constructor.
         *
         * @since       0.1.0
         */
        DynamicArray ();

        /**
         * Initializing constructor. Sets max size to \p maxSize,
         * effectively overriding the default.
         *
         * @param       maxSize         (size_t) Maximum size of the
         *                              array.
         * @since       0.1.0
         */
        DynamicArray (size_t maxSize);

        /**
         * Initializing constructor. Sets max size to \p maxSize and
         * filling each element of the array with \p fill.
         *
         * @param       maxSize         (size_t) Maximum size of the
         *                              array.
         * @param       fill            (T) Contents of each element.
         * @since       0.1.0
         */
        DynamicArray (size_t maxSize, T fill);

        /**
         * Copy constructor.
         *
         * The source DynamicArray can be of any size, as long as they
         * are the same type.
         *
         * @param       arr             (const DynamicArray &) The
         *                              source DynamicArray.
         * @since       0.1.0
         */
        DynamicArray (const DynamicArray & arr);

        /**
         * Destructor.
         *
         * @since       0.1.0
         */
        ~DynamicArray (void);

        /**
         * Sets maxSize equal to currentSize.
         *
         * @param       (void)
         * @since       0.1.0
         */
        void resize (void);

        /**
         * Sets a new maxSize.
         *
         * If maxSize is less than _currentSize,
         * then the array is truncated. If maxSize is greater than
         * currentSize, then the array is made larger and the new
         * elements are not initialized to anything. If maxSize is the
         * same as currentSize, then nothing happens except for the
         * removal of uninitialized elements.
         *
         * @param       maxSize         The new maximum size of the
         *                              array.
         * @since       0.1.0
         */
        void resize (size_t maxSize);
        
        /**
         * Query the maximum size of the array.
         *
         * @param       (void)
         * @since       0.1.0
         */
        const size_t maxSize (void);
        
        /**
         * Assignment operator.
         *
         * Assigns the right hand side of the assignment operator to
         * the left.
         * @param       rhs             (const DynamicArray &) The
         *                              source DynamicArray.
         * @since 0.1.0
         */
        const DynamicArray & operator = (const DynamicArray &);
};

#include "DynamicArray.cpp"

#endif      // _DYNAMIC_ARRAY_H_

