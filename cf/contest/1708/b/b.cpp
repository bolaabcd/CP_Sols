#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n,l,r;
	cin >> n >> l >> r;
	vector<int> ans;
	for(int i = 1; i <= n; i++) {
		ans.push_back(l+((2123456789/i)*i-l)%i);
		if(ans.back() > r) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	for(int i: ans)
		cout << i << ' ';
	cout << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
