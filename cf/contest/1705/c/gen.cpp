#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int rand(int a, int b) {// [a,b]
    return rand()%(b-a+1) + a;
}

int main(int argc, char** argv) {
    srand(atoi(argv[1]));
	cout << 1 << endl;
	int n = 5, c = 3, q = 100;
	cout << n <<' ' << c << ' ' << q << endl;
	for(int i = 0; i < n; i++)
		cout << char('a'+rand(0,26));
	cout << endl;
	for(int i = 0; i < c; i++) {
		int l = rand(1,n), r = rand(1,n);
		cout << min(l,r) << ' ' << max(l,r) << endl;
		n += max(l,r)-min(l,r)+1;
	}
	for(int i = 0; i < q; i++)
		cout << rand(1,n) << endl;
}
