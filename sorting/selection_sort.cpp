// O(n^2) on best-case, worst-case and average-case, not stable.
// The best if we have a lot of satellite data and want something simple.

#ifndef SELECTION_SORT_ALG
#define SELECTION_SORT_ALG

#include "utility/swap.cpp" 

template <class RandomAccessIterator>
inline void selection_sort(RandomAccessIterator begin, RandomAccessIterator end) {
    for(auto i = begin; i != end; i++) {
        auto smallest = *i;
        auto smallest_ptr = i;
        for(auto j = i+1; j != end; j++) {
            if(*j < smallest){
                smallest = *j;
                smallest_ptr = j;
            }
        }
        swap(*smallest_ptr,*i);
    }
}

#endif