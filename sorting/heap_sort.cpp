// O(n log(n)) on worst, best and average cases. Not stable, in-place.
// Execution time does not depend much on input configuration.

#ifndef HEAP_SORT_ALG
#define HEAP_SORT_ALG

#include "utility/swap.cpp"
#include "structures/max_heap.cpp"

template <class RandomAccessIterator>
inline void heap_sort(RandomAccessIterator begin, RandomAccessIterator end) {
    Max_Heap<typename RandomAccessIterator::value_type>::build(begin,end--);

    while(end != begin) {
        swap(*end,*begin);
        Max_Heap<typename RandomAccessIterator::value_type>::fix_down(begin,end--,begin);
    }
}


template <class T>
inline void heap_sort(T* begin, T* end) {
    Max_Heap<T>::build(begin,end--);

    while(end != begin) {
        swap(*end,*begin);
        Max_Heap<T>::fix_down(begin,end--,begin);
    }
}

#endif