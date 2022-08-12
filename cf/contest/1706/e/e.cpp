#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n,m,q;
vector<vector<pair<int,int>>> gr; // to where, using which edge
vector<bool> marc;

void dfs(int i, int k) {
	if(marc[i])
		return;
	marc[i] = true;
	for(auto [j,e] : gr[i])
		if(e <= k)
			dfs(j,k);
}

bool conn(int l, int r, int k) {
	marc.clear();
	marc.resize(n,false);
	dfs(l,k);
	for(int i = l; i <= r; i++)
		if(!marc[i]) return false;
	return true;
}

void solve() {
	gr.clear();
	cin >> n >> m >> q;
	gr.resize(n);
	for(int i = 0; i < m; i++) {
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		gr[u].pb({v,i});
		gr[v].pb({u,i});
	}
	for(int i = 0; i < q; i++) {
		int lq,rq;
		cin >> lq >> rq;
		lq--;
		rq--;
		int kl = 0, kr = m-1;
		while(kl != kr) {
			int mid = (kl+kr)/2;
			if(conn(lq,rq,mid))
				kr = mid;
			else
				kl = mid+1;
		}
		if(lq == rq) kl = -1;
		cout << kl+1 << ' ';
	}
	cout << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
