#include <bits/stdc++.h>
#include "utility/print_vec.cpp"
#include "sorting/quick_sort.cpp"
#include "sorting/merge_sort.cpp"
#include "sorting/heap_sort.cpp"

using namespace std;

int main() {
    int vec[10] = {10,9,8,7,6,5,4,3,2,1};
    quick_sort(vec,vec+10);
    print_vec(vec,vec+10,cout);

    int vec2[10] = {10,9,8,7,6,5,4,3,2,1};
    merge_sort(vec2,vec2+10);
    print_vec(vec2,vec2+10,cout);

    // int vec3[10] = {1,2,3,4,5,6,7,8,9,10};
    int vec3[10] = {10,9,8,7,6,5,4,3,2,1};
    heap_sort(vec3,vec3+10);
    print_vec(vec3,vec3+10,cout);

    vector<int> vec4 = {10,9,8,7,6,5,4,3,2,1};
    quick_sort(vec4.begin(),vec4.end());
    print_vec(vec4.begin(),vec4.end(),cout);

    vec4 = {10,9,8,7,6,5,4,3,2,1};
    merge_sort(vec4.begin(),vec4.end());
    print_vec(vec4.begin(),vec4.end(),cout);

    // vec4 = {1,2,3,4,5,6,7,8,9,10};
    vec4 = {10,9,8,7,6,5,4,3,2,1};
    heap_sort(vec4.begin(),vec4.end());
    print_vec(vec4.begin(),vec4.end(),cout);
}