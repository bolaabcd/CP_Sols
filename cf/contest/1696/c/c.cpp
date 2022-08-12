#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
ll m;
ll mi(ll val) {
	while(val%m == 0)val/=m;
	return val;
}

void solve() {
	int n,k;
	cin >> n >> m;
	vector<ll> a(n);
	for(ll&i:a)cin>>i;
	cin >> k;
	vector<ll> b(k);
	for(ll&i:b)cin>>i;

	vector<pair<ll,ll>> b2, a2;//val amt
	
	a2.push_back({-INF,-INF});
	b2.push_back({-INF,-INF});

	for(int i = 0; i < n; i++) {
		ll mdiv = mi(a[i]);
		if(mdiv == a2.back().first) {
			a2.back().second += a[i]/mdiv;
		} else
			a2.push_back({mdiv,a[i]/mdiv});
	}
	for(int i = 0; i < k; i++) {
		ll mdiv = mi(b[i]);
		if(mdiv == b2.back().first) {
			b2.back().second += b[i]/mdiv;
		} else
			b2.push_back({mdiv,b[i]/mdiv});
	}

	// for(auto pa: a2) cout << pa.first << '_' << pa.second << ' ';
	// cout << endl;
	// for(auto pa: b2) cout << pa.first << '_' << pa.second << ' ';
	// cout << endl;

	if(a2 == b2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
