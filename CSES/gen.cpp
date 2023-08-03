#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b) {
	return rand()%(b-a+1)+a;
}

int main(int argc, char** argv) {
	srand(atoi(argv[1]));
	int n = 4, k = rand(2,3);
	cout << n << ' ' <<  k << endl;
	for(int i = 0; i < n; i++)
		cout << rand(1,5) << ' ';
	cout << endl;
}
