// SEARCH: Not implemented.
// INSERT: O(log(n))
// DELETE: O(log(n)).
// MINIMUM: Not implemented.
// MAXIMUM: O(1).
// SUCCESSOR: Not implemented.
// PREDECESSOR: Not implemented.

// SPECIAL POWERS: -

// STATIC UTILITIES: Build and fix heap, useful for heapsort.

#ifndef HEAP_STRUCTURE_DEFINITION
#define HEAP_STRUCTURE_DEFINITION

#include <vector>
#include <assert.h>
#include "utility/swap.cpp"
#include <iostream>

template <class T>
class Max_Heap
{
private:
    int size;
    std::vector<T> max_heap;

public:
    Max_Heap();
    Max_Heap(int initial_size);
    void insert(T t);
    void print_heap(std::ostream& out);
    T maximum();
    T pop_max();
    ~Max_Heap();

    template <class RandomAccessIterator>
    static void fix_down(RandomAccessIterator begin, RandomAccessIterator end, RandomAccessIterator pos);
    template <class RandomAccessIterator>
    static void build(RandomAccessIterator begin, RandomAccessIterator end);
    template <class RandomAccessIterator>
    static void fix_up(RandomAccessIterator begin, RandomAccessIterator end, RandomAccessIterator pos);
};

template <class T>
Max_Heap<T>::Max_Heap()
{
    this->size = 0;
}

template <class T>
Max_Heap<T>::Max_Heap(int initial_size)
{
    this->size = initial_size;
    this->max_heap.resize(initial_size);
}

template <class T>
Max_Heap<T>::~Max_Heap(){
    max_heap.clear();
}



template <class T>
void Max_Heap<T>::insert(T t){
    this->size++;
    this->max_heap.resize(this->size);
    this->max_heap[this->size-1] = t;
    
    Max_Heap::fix_up(this->max_heap.begin(),this->max_heap.end(),this->max_heap.end()-1);
}

template <class T>
T Max_Heap<T>::maximum(){
    return this->max_heap[0];
}

template <class T>
void Max_Heap<T>::print_heap(std::ostream& out){
    for(int i = 0; i < this->size; i++) {
        out << this->max_heap[i] << " ";
    }
    out << std::endl;
}

template <class T>
T Max_Heap<T>::pop_max(){
    assert(this->size > 0);
    T max = this->max_heap[0];

    this->max_heap[0] = this->max_heap[--this->size];
    this->max_heap.resize(this->size);

    Max_Heap::fix_down(this->max_heap.begin(),this->max_heap.end(),this->max_heap.begin());

    return max;
}


template <class T>
template <class RandomAccessIterator>
void Max_Heap<T>::fix_down(RandomAccessIterator begin, RandomAccessIterator end, RandomAccessIterator pos){
    int ipos = pos-begin, siz = end-begin; // ipos is 0-based
    if(siz == 0 || siz == 1)
        return;
    assert(ipos >= 0 && ipos < siz);
    if(2*(ipos+1)+1 <= siz) {
        auto ch1 = begin + (2*(ipos+1)-1),ch2 = begin + (2*(ipos+1)+1-1);
        auto maxch = *ch1 > *ch2 ? ch1 : ch2;
        if(*maxch > *pos){
            swap(*pos,*maxch);
            Max_Heap::fix_down(begin,end,maxch);
        }
    } else if (2*(ipos+1) <= siz) {
        auto ch1 = begin + (2*(ipos+1)-1);
        if(*ch1 > *pos){
            swap(*pos,*ch1);
            Max_Heap::fix_down(begin,end,ch1);
        }
    }
}

template <class T>
template <class RandomAccessIterator>
void Max_Heap<T>::build(RandomAccessIterator begin, RandomAccessIterator end){
    auto init = begin + ((end-begin)/2-1);
    for(auto i = init; i != begin-1; i--) {
        Max_Heap::fix_down(begin,end,i);
    }
}

template <class T>
template <class RandomAccessIterator>
void Max_Heap<T>::fix_up(RandomAccessIterator begin, RandomAccessIterator end, RandomAccessIterator pos){
    int ipos = pos-begin, siz = end-begin; // ipos is 0-based
    assert(ipos >= 0 && ipos < siz);
    for(auto i = pos; i != begin; i = begin+ipos) {
        ipos/=2;
        if(*i > *(begin+ipos)) {
            swap(*i,*(begin+ipos));
        } else {
            break;
        }
    }
}

#endif