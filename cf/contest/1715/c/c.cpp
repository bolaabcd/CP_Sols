#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	for(int&i:a)cin>>i;
	set<int> ls;
	int val = a[0];
	for(int i = 1; i < n; i++) {
		if(a[i] != val) {
			ls.insert(i);
			val = a[i];
		}
	}
	ls.insert(n);

	ll lans = 0;
	ll prev = 0, sizat = ls.size();
	for(int i: ls) {
		lans += (i-prev)*sizat;
		prev = i;
		sizat--;
	}
	assert(sizat == 0);
	for(int i = 0; i < m; i++) {
		int p,x;
		cin >> p >> x;
		p--;
		if(p > 0 and a[p] == a[p-1] and x != a[p]) {
			ls.insert(p);
		}
		if(p < n and a[p] == a[p+1] and x != a[p]) {
			ls.insert(p+1);
		}
		if(p > 0 and a[p] != a[p-1] and x == a[p-1]) {
			ls.erase(p);
		}
		if(p < n and a[p] != a[p+1] and x == a[p+1]) {
			ls.erase(p+1);
		}
		a[p] = x;

	}
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
