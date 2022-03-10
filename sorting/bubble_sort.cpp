// O(n^2) on worst and average case, stable.
// Only relevant because it's ultra simple.

#ifndef BUBBLE_SORT_ALG
#define BUBBLE_SORT_ALG

#include "utility/swap.cpp" 

template <class RandomAccessIterator>
inline void bubble_sort(RandomAccessIterator begin, RandomAccessIterator end) {
    for(auto i = begin; i != end; i++) {
        for(auto j = begin+1; j != end; j++) {
            if(*(j-1) > *(j)){
                swap(*j,*(j-1));
            }
        }
    }
}

#endif