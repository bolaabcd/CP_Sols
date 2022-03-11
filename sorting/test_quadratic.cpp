#include <bits/stdc++.h>
#include "utility/print_vec.cpp"
#include "sorting/insertion_sort.cpp"
#include "sorting/bubble_sort.cpp"
#include "sorting/selection_sort.cpp"

using namespace std;

int main() {
    int vec[10] = {10,9,8,7,6,5,4,3,2,1};
    insertion_sort(vec,vec+10);
    print_vec(vec,vec+10);

    int vec2[10] = {10,9,8,7,6,5,4,3,2,1};
    bubble_sort(vec2,vec2+10);
    print_vec(vec2,vec2+10);

    int vec3[10] = {10,9,8,7,6,5,4,3,2,1};
    selection_sort(vec3,vec3+10);
    print_vec(vec3,vec3+10);

    vector<int> vec4 = {10,9,8,7,6,5,4,3,2,1};
    insertion_sort(vec4.begin(),vec4.end());
    print_vec(vec4.begin(),vec4.end());

    vec4 = {10,9,8,7,6,5,4,3,2,1};
    bubble_sort(vec4.begin(),vec4.end());
    print_vec(vec4.begin(),vec4.end());

    vec4 = {10,9,8,7,6,5,4,3,2,1};
    selection_sort(vec4.begin(),vec4.end());
    print_vec(vec4.begin(),vec4.end());
}