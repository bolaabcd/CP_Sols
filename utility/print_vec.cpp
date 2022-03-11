// Prints a vector of elements

#ifndef PRINT_VECTOR_OF_ELEMENTS
#define PRINT_VECTOR_OF_ELEMENTS

#include <iostream>

template <class RandomAccessIterator>
inline void print_vec(RandomAccessIterator begin, RandomAccessIterator end, std::ostream &out) {
    for(auto i = begin; i != end; i++)
        out << *i << " "; 
    out << std::endl;
}

#endif