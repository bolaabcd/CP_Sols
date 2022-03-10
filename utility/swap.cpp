// Swaps two elements

#ifndef SWAP_TWO_ELEMENTS
#define SWAP_TWO_ELEMENTS

template<class T> void swap(T& a, T&b) {
    T tmp = a;
    a = b;
    b = tmp;
}

#endif