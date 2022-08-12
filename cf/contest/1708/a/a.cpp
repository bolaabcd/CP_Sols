#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n, v;
	cin >> n;
	bool no = false;
	for(int i = 0; i < n; i++) {
		if(i == 0)
			cin >> v;
		else {
			int x;
			cin >> x;
			if(x%v)
				no = true;
		}
	}
	if(no)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	exit(0);
}
