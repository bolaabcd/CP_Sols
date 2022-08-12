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
	vector<int> hs(2*n);
	for(int i = 0; i < 2*n; i++) {
		cin >> hs[i];
	}
	sort(hs.begin(),hs.end());
	for(int i = 0; i < n; i++) {
		if(hs[i] + x > hs[i+n]){ 
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	return;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
