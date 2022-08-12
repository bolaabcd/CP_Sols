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
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	reverse(a.begin(),a.end());
	set<int> vs;
	for(int i = 0; i < n; i++) {
		if(vs.count(a[i])) {
			cout << n-i << endl;
			return;
		}
		vs.insert(a[i]);
	}
	cout << 0 << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
