#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool solve() {
	int n;
	cin >> n;
	int diff = 0;
	for(int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if(abs(diff+p) >= abs(diff-p)) {
			if(abs(diff + p) <= 5)
				diff += p;
			else if (abs(diff-p) <= 5)
				diff -= p;
			else
				return false;
		} else {
			if(abs(diff - p) <= 5)
				diff -= p;
			else if (abs(diff + p) <= 5)
				diff += p;
			else
				return false;
		}
	}
	return true;
}

int main() { _
	int t;
	cin >> t;
	while(t--)
		if(solve())
			cout << "Feliz Natal!" << endl;
		else
			cout << "Ho Ho Ho!" << endl;
	exit(0);
}
