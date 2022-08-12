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
	vector<ll> h(n,0),pref(n,0); // if odd, prefix; if pair, sufix
	for(ll&i:h)cin>>i;
	ll tot1 = 0, tot2 = LINF;
	for(int i = 1; i < h.size()-1; i += 2) {
		tot1 += max(max(h[i-1],h[i+1])+1-h[i],0LL);
		pref[i] = tot1;
	}
	if(!(n%2)) {
		tot2 = 0;
		for(int i = 2; i < h.size()-1; i += 2) {
			tot2 += max(max(h[i-1],h[i+1])+1-h[i],0LL);
		}
		ll tottmp = 0;
		for(int i = 2; i < h.size()-1; i += 2) {
			pref[i] = tot2-tottmp;
			tottmp += max(max(h[i-1],h[i+1])+1-h[i],0LL);
		}
		for(int i = 2; i < h.size()-2; i += 2) {
			ll tot3 = pref[i-1] + pref[i+2];
			tot2 = min(tot3,tot2);
		}
	}
	cout << min(tot1,tot2) << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	exit(0);
}
