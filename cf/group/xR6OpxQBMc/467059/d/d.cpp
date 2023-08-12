#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	ll n,k;
	cin >> n >> k;
	if(n==1) {
		ll tot = 0;
		for(ll i = 0; i < n*k; i++) {
			ll x;
			cin >> x;
			tot += x;
		}
		cout << tot << endl;
		return;
	}
	vector<vector<ll>> ans(k);
	ll kk = 0;
	ll kkk = 0;
	bool wow = false;
	for(ll i = 0; i < n*k; i++) {
		ll x;
		cin >> x;
		if(!kk and ans[0].size()+1-1 == (n+1)/2-1)
			wow = true;
		if(wow) {
			if(ans[kkk].size() == n)
				kkk++;
			ans[kkk].pb(x);
			continue;
		}
		ans[kk].pb(x);
		kk++;
		kk%=k;
	}
	ll resp = 0;
	for(int i = 0; i < k; i++)
		resp += ans[i][(n+1)/2-1];
	cout << resp << endl;
}

int main() { __
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
