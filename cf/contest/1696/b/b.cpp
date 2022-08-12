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
	vector<int> vec(n);
	for(int&i:vec)cin>>i;
	vec.push_back(0);
	int ld = -1, amt = 0;
	for(int i = 0; i < n+1; i++) {
		if(vec[i] == 0) {
			if(ld != -1)
				amt++;
			ld = -1;
		} else {
			ld = i;
		}
	}

	cout << min(amt,2) << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	exit(0);
}
