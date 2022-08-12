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
	int m = 4;
	cout << m << endl;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < m; j++)
			if(i == 0 and j ==0)
				cout << 0 << ' ';
			else
				cout << rand(0,int(3)) << ' ';
		cout << endl;
	}
}
