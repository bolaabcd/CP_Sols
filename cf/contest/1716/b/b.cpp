#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n;
	cin >> n;
	cout << n << endl;
	vector<int> perm(n);
	iota(perm.begin(),perm.end(),1);
	for(int j:perm)
		cout << j << ' ';
	cout << endl;
	for(int i = 1; i < n; i++) {
		swap(perm[i],perm[i-1]);
		for(int j:perm)
			cout << j << ' ';
		cout << endl;
	}
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
