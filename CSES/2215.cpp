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
	if(n > k*k) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	vector<int> ans(n);
	int x = k, ant = 0;
	vector<bool> foi(n,false);
	for(int i = n-1; i >= 0; i--) {
		ans[i] = x;
		if(foi[x-1]) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		x--;
		foi[x] = true;
		if(x == ant) {
			ant += k;
			x = min(n,ant+k);
		}
	}
	for(int i : ans)
		cout << i << ' ';
	cout << endl;
}

int main() { __
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
