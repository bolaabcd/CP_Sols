#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for(int &i:a) cin >> i;
	for(int& i: b) cin >> i;

	int eq = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == b[i])
			eq++;
	}

	cout << eq << endl;

	// sort(a.begin(), a.end());
	// sort(b.begin(), b.end());

	ll seq = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i] == b[j] && i!=j)
				seq ++;			
		}
	}

	cout << seq << endl;

	exit(0);
}
