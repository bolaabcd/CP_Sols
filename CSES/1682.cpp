#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> gr[112345], grr[112345];
bool mark[112345];

void dfs(int i) {
	if(mark[i])
		return;
	mark[i] = true;
	for(int j : gr[i])
		dfs(j);
}

void dfsr(int i) {
	if(!mark[i])
		return;
	mark[i] = false;
	for(int j : grr[i])
		dfsr(j);
}

int main() { __
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		gr[a].pb(b);
		grr[b].pb(a);
	}
	dfs(0);
	for(int i = 0; i < n; i++)
		if(!mark[i]) {
			cout << "NO" << endl;
			cout << 1 << ' ' << i+1 << endl;
			exit(0);
		}
	dfsr(0);
	for(int i = 0; i < n; i++)
		if(mark[i]) {
			cout << "NO" << endl;
			cout << i+1 << ' ' << 1 << endl;
			exit(0);
		}
	cout << "YES" << endl;
	exit(0);
}
