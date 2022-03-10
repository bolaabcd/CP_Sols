#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int rand(int a, int b) {// [a,b]
    return rand()%(b-a+1) + a;
}

int main(int argc, char** argv) {
    srand(atoi(argv[1]));
    int n = 5;
    cout << n << endl;
    for(int i = 2; i <= n; i++) {
        cout << rand(1,i-1) << " " << i << endl;
    }
}