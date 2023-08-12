#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
#define pii pair<ll,ll>

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n;
	cin >> n;
	map<ll,vector<int>> rec; // indices com cada valor
	map<ll,ll> mp; // qtdd de cada valor
	for(int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		mp[x]++;
		rec[x].pb(i);
	}
	if(n == 1) {
		cout << 1 << endl;
		return;
	}
	vector<pii> vec; // valor, qtdd
	for(auto [a,b] : mp)
		vec.pb({a,b});
	int n2 = vec.size();
	vector<ll> pref(n2,vec[0].s),suf(n2,vec[n2-1].s);
	for(int i = 1; i < n2; i++)
		pref[i] = vec[i].s + pref[i-1];
	for(int i = n2-2; i >= 0; i--)
		suf[i] = vec[i].s + suf[i+1];
	
	ll tot = 0;
	vector<ll> ans(n);
	for(int i = 1; i < n2; i++)
		tot += (vec[i].f-vec[i-1].f) * suf[i];
	tot += n;
	for(int i : rec[vec[0].f])
		ans[i] = tot;
	for(int i = 1; i < n2; i++) {
		tot += (vec[i].f-vec[i-1].f)*(pref[i-1]-suf[i]);
		for(int j : rec[vec[i].f])
			ans[j] = tot;
	}
	for(ll i : ans)
		cout << i << ' ';
	cout << endl;
}

int main() { __
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}

