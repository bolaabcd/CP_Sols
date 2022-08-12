#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5;

int cs[2][MAX];
int arr[MAX];

void solve() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cs[0][i] = 0;
		cs[1][i] = 0;
		cin >> arr[i];
		arr[i]--;
	}
	vector<bool> par(n,true);
	for(int i = 0; i < n; i++) {
		if(par[arr[i]] and !(i%2)) {
			cs[0][arr[i]]++;
			par[arr[i]] = false;
		} else if(!par[arr[i]] and i%2) {
			cs[0][arr[i]]++;
			par[arr[i]] = true;
		}
	}
	par.clear();
	par.resize(n,false);

	for(int i = 0; i < n; i++) {
		if(par[arr[i]] and !(i%2)) {
			cs[1][arr[i]]++;
			par[arr[i]] = false;
		} else if(!par[arr[i]] and i%2) {
			cs[1][arr[i]]++;
			par[arr[i]] = true;
		}
	}
	for(int i = 0; i < n; i++) {
		cout << max(cs[0][i],cs[1][i]) << ' ';
	}
	cout << endl;
}
int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
