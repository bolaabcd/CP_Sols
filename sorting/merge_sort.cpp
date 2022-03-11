// O(n log(n)) on worst, best and average cases. Not stable, not in-place.
// Execution time does not depend much on input configuration, the main problem is that it's not in-place.

#ifndef MERGE_SORT_ALG
#define MERGE_SORT_ALG

#include "utility/swap.cpp"

template <class RandomAccessIterator>
inline void merge_sort(RandomAccessIterator begin, RandomAccessIterator end) {
    if(end-begin == 1)
        return;
    auto mid = (end-begin)/2;
    merge_sort(begin,begin+mid);
    merge_sort(begin+mid,end);


    typename RandomAccessIterator::value_type* copy = new typename RandomAccessIterator::value_type[end-begin];
    for(auto i = begin, j = begin+mid, k = 0; i != begin+mid || j != end ; k++) {
        if(i == begin+mid) {
            copy[k] = *j;
            j++;
        } else if (j == end) {
            copy[k] = *i;
            i++;
        } else if (*j < *i) {
            copy[k] = *j;
            j++;
        } else {
            copy[k] = *i;
            i++;
        }
    }

    for(auto i = 0, j = begin; i < end-begin; i++, j++)
        *j = copy[i];

    delete[] copy;
}

template <class T>
inline void merge_sort(T* begin, T* end) {
    if(end-begin == 1)
        return;
    auto mid = (end-begin)/2;
    merge_sort(begin,begin+mid);
    merge_sort(begin+mid,end);


    T* copy = new T[end-begin];
    for(auto i = begin, j = begin+mid, k = 0; i != begin+mid || j != end ; k++) {
        if(i == begin+mid) {
            copy[k] = *j;
            j++;
        } else if (j == end) {
            copy[k] = *i;
            i++;
        } else if (*j < *i) {
            copy[k] = *j;
            j++;
        } else {
            copy[k] = *i;
            i++;
        }
    }

    for(auto i = 0, j = begin; i < end-begin; i++, j++)
        *j = copy[i];

    delete[] copy;
}


#endif