#include <bits/stdc++.h>
#include "sorting/insertion_sort.cpp"
#include "sorting/bubble_sort.cpp"
#include "sorting/selection_sort.cpp"

using namespace std;

int main() {
    int vec[10] = {10,9,8,7,6,5,4,3,2,1};
    insertion_sort(vec,vec+10);
    bubble_sort(vec,vec+10);
    selection_sort(vec,vec+10);
    for(int i = 0; i < 10; i++)
        cout << vec[i] << " ";
    cout << endl;

    vector<int> vec2 = {10,9,8,7,6,5,4,3,2,1};
    insertion_sort(vec2.begin(),vec2.end());
    bubble_sort(vec2.begin(),vec2.end());
    selection_sort(vec2.begin(),vec2.end());
    for(int i = 0; i < 10; i++)
        cout << vec2[i] << " ";
    cout << endl;
}