#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll initn;

ll realp(ll l, vector<pair<ll,ll>> &wh) {
	ll lb = 0,r = wh.size()-1;
	while(lb != r) {
		ll mid = (lb+r+1)/2;
		if(wh[mid].first <= l)
			lb = mid;
		else
			r = mid-1;
	}
	ll ans = wh[lb].second+l-wh[lb].first;
	if(ans >= initn)
		return realp(ans,wh);
	else
		return ans;
}

void solve() {
	ll n,c,q;
	cin >> initn >> c >> q;
	n = initn;
	string s;
	cin >> s;
	vector<pair<ll,ll>> wh(1,{0,0}); // initial position (n) and position to look for (l)
	for(int i = 0; i < c; i++) {
		ll l,r;
		cin >> l >> r;
		l--;
		r--;
		wh.push_back({n,l});
		n += r-l+1;
	}
	for(int i = 0; i < q; i++) {
		ll k;
		cin >> k;
		k--;
		cout << s[realp(k,wh)] << endl;
	}
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
