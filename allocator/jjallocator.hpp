/**
 * @file jjallocator.hpp 
 * @brief a simple allocator
 * @version 0.1
 * @date 2024-02-03
 * 
 */

#pragma once

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>

namespace jj {

template<class T>
inline T* _allocate(ptrdiff_t size, T*)
{
    std::set_new_handler(0);

    std::cout << "required size = " << size << std::endl;
    std::cout << "size of object = " << sizeof(T) << std::endl;
    std::cout << "allocating " << (size_t)(size * sizeof(T)) << " bytes" << std::endl;

    T* tmp = (T*)(::operator new((size_t)(size * sizeof(T))));
    if (tmp == 0)
    {
        std::cerr << "out of memory" << std::endl;
        exit(1);
    }
    return tmp;
}

template<class T>
inline void _deallocate(T* buffer)
{
    ::operator delete(buffer);
}

template<class T1, class T2>
inline void _construct(T1* p, const T2& value)
{
    new(p) T1(value);  // placement new. invoke constructor of T1
}

template <class T>
inline void _destory(T* ptr)
{
    ptr->~T();
}


template <class T>
class allocator
{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    // rebind allocator of type U
    template <class U>
    struct rebind
    {
        typedef allocator<U> other;
    };

    // hint used for locality
    pointer allocate(size_type n, const void* hint=0)
    {
        return _allocate((difference_type)n, (pointer)0);
    }

    void deallocate(pointer p, size_type n) { _deallocate(p); };

    void construct(pointer p, const T& value)
    {
        _construct(p, value);
    }

    pointer address(reference x) { return (pointer)&x; }

    const_pointer const_address(const_reference x) 
    {
        return (const_pointer)&x;
    }

    size_type max_size() const
    {
        return std::max(size_type(1), size_type(UINT_MAX/sizeof(T)));
    }

};

}
