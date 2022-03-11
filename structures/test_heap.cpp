#include <bits/stdc++.h>
#include "structures/max_heap.cpp"
#include "utility/print_vec.cpp"

using namespace std;

int main() {
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    Max_Heap<int> mh;

    for(int i: vec){
        mh.insert(i);
        mh.print_heap(cout);
    }

    cout << std::endl;

    for(int i:vec) {
        cout << mh.maximum() << ' ' << mh.pop_max() << endl;
        mh.print_heap(cout);
    }

    // cout << '\n';

    vec = {1,2,3,4,5,6,7,8,9,10};
    Max_Heap<int>::build(vec.begin(),vec.end());
    print_vec(vec.begin(), vec.end(), cout);

    cout << "\n\n\n";

    int array1[] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i++){
        mh.insert(array1[i]);
        mh.print_heap(cout);
    }

    cout << std::endl;

    for(int i = 0; i < 10; i++) {
        cout << mh.maximum() << ' ' << mh.pop_max() << endl;
        mh.print_heap(cout);
    }

    // cout << '\n';

    int array2[] = {1,2,3,4,5,6,7,8,9,10};
    Max_Heap<int>::build(array2,array2+10);
    print_vec(array2, array2+10, cout);
}