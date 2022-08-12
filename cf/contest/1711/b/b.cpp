#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5+100;
int uh[MAX], nei[MAX], xs[MAX], ys[MAX];

void solve() {
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> uh[i];
	int mini2 = INF;
	for(int i = 0; i < n; i++)
		nei[i] = 0;
	for(int i = 0; i < m; i++) {
		int x,y;
		cin >> x >> y;
		nei[x-1]++;
		nei[y-1]++;
		xs[i] = x-1;
		ys[i] = y-1;
	}
	for(int i = 0; i < m; i++) {
		if ((nei[xs[i]] + nei[ys[i]]-1)%2)
			mini2 = min(mini2, uh[xs[i]] + uh[ys[i]]);
	}
	if(m%2) {
		int mini = INF;
		for(int i = 0; i < n; i++)
			if(nei[i]%2)
				mini = min(mini, uh[i]);
		cout << min(mini,mini2) << endl;
	} else
		cout << 0 << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
