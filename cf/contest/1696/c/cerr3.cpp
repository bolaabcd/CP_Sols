#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool test(ll l, ll m, ll r) {
	while(l%m == 0 and l != r)
		l/=m;
	return l == r;
}

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
		if(a[i] == b[j]) {
			i++;
			j++;
			continue;
		} else if (a[i] > b[j]){
			ll sum = 0;
			int r;
			for(r = 0; sum < a[i] and j+r < k; r++) {
				if(!test(a[i], m, b[i])){
					cout << "No" << endl;
					return;
				}
				sum += b[j+r];
			}
			if(sum == a[i]) {
				i++;
				j += r;
			} else {
				cout << "No" << endl;
				return;
			}
		} else {
			ll sum = 0;
			int r;
			for(r = 0; sum < b[j] and i+r < n; r++) {
				if(!test(b[j], m, a[i])){
					cout << "No" << endl;
					return;
				}
				sum += a[i+r];
			}
			if(sum == b[j]) {
				i+=r;
				j++;
			} else {
				cout << "No" << endl;
				return;
			}
		}
	}
	if(i != n or j != k)
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
