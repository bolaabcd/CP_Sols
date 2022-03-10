// O(n^2) on worst-case and average-case, O(n) if ordered, stable.
// The best for very small inputs.

#ifndef INSERTION_SORT_ALG
#define INSERTION_SORT_ALG

#include "utility/swap.cpp" 

template <class RandomAccessIterator>
inline void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end) {
    for(auto i = begin+1; i != end; i++) {
        for(auto j = i; j != begin; j--) {
            if(*j < *(j-1)){
                swap(*j,*(j-1));
            }
            else
                break;
        }
    }
}

#endif