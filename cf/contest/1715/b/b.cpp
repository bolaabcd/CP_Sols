#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	ll n,k,b,s;
	cin >> n >> k >> b >> s;
	if(s < k*b or k*b+k*n-n < s) {
		cout << -1 << endl;
	} else {
		s -= k*b;
		ll val = k*b + min(k-1,s);
		cout << val << ' ';
		s -= min(k-1,s);
		for(int i = 1; i < n; i++) {
			val = min(k-1,s);
			cout << val << ' ';
			s -= val;
		}
		cout << endl;
	}
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
