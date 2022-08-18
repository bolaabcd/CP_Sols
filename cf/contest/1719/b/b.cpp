#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n,k;
	cin >> n >> k;
	if(k%4 == 0)
		cout << "NO" << endl;
	else if(k%4 == 2) {
		cout << "YES" << endl;
	for(int i = 0; i+2 <= n; i += 4) {
			cout << i+2 << ' ' << i+1 << endl;
			if(i + 4 <= n)
			cout << i+3 << ' ' << i+4 << endl;
		}
	}else {
		cout << "YES" << endl;
		for(int i = 1; i <= n; i += 2)
			cout << i << ' ' << i+1 << endl;
	}
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	exit(0);
}
