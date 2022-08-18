#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n,q;
	cin >> n >> q;
	vector<int> v(n);
	for(int&i:v)cin>>i;
	vector<bool> b(n);
	vector<int> ne(n);
	stack<pair<int,int>> nv;
	for(int i = n-1; i >= 0; i--) {
		while(!nv.empty() and nv.top().first < v[i])
			nv.pop();
		if(nv.empty())
			ne[i] = n;
		else
			ne[i] = nv.top().second;
		nv.push({v[i],i});
	}

	int big = -INF;
	for(int i = 0; i < n; i++) {
		if(v[i] > big) {
			big = v[i];
			b[i] = true;
		} else {
			b[i] = false;
		}
	}
	for(int j = 0; j < q; j++) {
		int i, k;
		cin >> i >> k;
		i--;
		if(!b[i]) {
			cout << 0 << endl;
		} else {
			k -= i;
			if (k < 0)
				cout << 0 << endl;
			else if (big == v[i]) {
				cout << k+(i != 0) << endl;
			}
			else {
				cout << (i != 0)+min(k,ne[i]-i-1) << endl;
			}
		}
	}
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	exit(0);
}
