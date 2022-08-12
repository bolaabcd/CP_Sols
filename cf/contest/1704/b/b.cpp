#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n,x;
	cin >> n >> x;
	int mini = -INF, maxi = INF;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		mini = max(mini, a-x);
		//mini = max(mini, x-a);
		maxi = min(maxi, a+x);
		//cout << a << ' ' << mini << ' ' << maxi << endl;
		if(mini > maxi) {
			mini = a-x;
			maxi = a+x;
			ans++;
		}
	}
	cout << ans << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
