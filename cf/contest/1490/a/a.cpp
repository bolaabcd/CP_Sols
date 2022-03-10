#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 60;

int vec[MAX];

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	int ans = 0;
	for(int i = 0; i < n-1; i++) {
		//double frac = max(vec[i],vec[i+1])/min(vec[i],vec[i+1]);
		//ans += max(ceil(log2(frac))-1,0.0);
		int mini = min(vec[i],vec[i+1]), maxi = max(vec[i],vec[i+1]);
		while(2*mini < maxi) {
			mini *=2;
			ans ++;
		}
	}
	cout << ans << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	exit(0);
}
