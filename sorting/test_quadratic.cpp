#include <bits/stdc++.h>

template<class T> void swap(T& a, T&b) {
    T tmp = a;
    a = b;
    b = tmp;
}

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

using namespace std;

int main() {
    int vec[10] = {10,9,8,7,6,5,4,3,2,1};
    // vector<int> vec = {10,9,8,7,6,5,4,3,2,1};
    insertion_sort(vec,vec+10);
    // insertion_sort(vec.begin(),vec.end());
    bubble_sort(vec,vec+10);
    // bubble_sort(vec.begin(),vec.end());
    selection_sort(vec,vec+10);
    // selection_sort(vec.begin(),vec.end());
    for(int i = 0; i < 10; i++)
        cout << vec[i] << " ";
    cout << endl;
}