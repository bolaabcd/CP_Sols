#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n,k;
	ll m;
	cin >> n >> m;
	vector<ll> a(n);
	for(ll&i:a)cin>>i;
	cin >> k;
	vector<ll> b(k);
	for(ll&i:b)cin>>i;

	int i = 0, j = 0;
	while(i < n and j < k) {
		if(a[i] == b[j]){
			i++;
			j++;
			continue;
		}
		if(m*b[j] == a[i]) {
			for(int r = 0; r < m; r++) {
				if(j+r >= k) {
					cout << "No" << endl;
					return;
				}
				if(b[j+r] != b[j]){
					cout << "No" << endl;
					return;
				}
			}
			j += m;
			i++;
		} else if (m*a[i] == b[j]) {
			for(int s = 0; s < m; s++) {
				if(i+s >= n) {
					cout << "No" << endl;
					return;
				}
				if(a[i+s] != a[i]){
					cout << "No" << endl;
					return;
				}
			}
			i += m;
			j++;
		} else if (a[i]%m != 0){
			cout << "No" << endl;
			return;
		} else {
			
		}
	}
	if (i != n or j != k)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
