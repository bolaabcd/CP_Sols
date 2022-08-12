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
	vector<ll> a(n);
	for(ll&i:a)cin>>i;
	int fnz = -1;
	ll tot = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > 0 and fnz == -1)
			fnz = i;
		else if (a[i] == 0 and fnz >= 0) {
			a[fnz]--;
			a[i]++;
			tot++;
			if(a[fnz] == 0)
				fnz++;
		}
	}
	for(int i = n-2; i >= 0; i--) {
		tot += a[i];
	}
	cout << tot << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
