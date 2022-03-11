// O(n^2) on worst-case, O(n log(n)) on best and average cases. Randomized and not stable, in-place.
// The fastest comparison sort on average for large inputs.

#ifndef QUICK_SORT_ALG
#define QUICK_SORT_ALG

#include "utility/rand.cpp"
#include "utility/swap.cpp"
#include <assert.h>

template <class RandomAccessIterator>
inline void quick_sort(RandomAccessIterator begin, RandomAccessIterator end) {
    if(end-begin <= 1)
        return;
    int pos = rand(1,end-begin);
    swap(*(end-1),*(end-pos));

    auto lptr = end-1;

    auto i = begin-1, j = begin;
    for(; j < lptr; j++) {
        if(*j < *lptr) {
            i++;
            swap(*i,*j);
        }
    }

    assert(j == lptr);
    i++;
    swap(*i,*lptr);
    quick_sort(begin,i);
    quick_sort(i+1,end);
}

#endif