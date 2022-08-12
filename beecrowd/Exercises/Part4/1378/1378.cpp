#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll distsq(pair<ll,ll> a, pair<ll,ll> b) {
	return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int main() { _
	while(1) {
		ll n;
		cin >> n;
		if (n == 0) break;
		
		vector<pair<ll, ll>> vals(n);
		for (auto& pa: vals) cin >> pa.first >> pa.second;
		ll tot = 0;
		for (ll i = 0; i < n; i++) {
			map<ll, ll> dist_amt;
			for (ll j = 0; j < n; j++) {
				dist_amt[distsq(vals[i], vals[j])]++;
			}
			for(auto& pa: dist_amt)
				tot += (pa.second*(pa.second-1))/2;
		}
		
		cout << tot << endl;
	}
	exit(0);
}

