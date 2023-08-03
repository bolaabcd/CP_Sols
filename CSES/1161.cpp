#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define pa pair<ll,int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int x,n;
vector<vector<int>> tr;
vector<ll> rev;
ll prof;
ll dfs(int i) {
	if(i < n) {
		assert(tr[i].size() == 0);
		return prof*rev[i];
	}
	assert(tr[i].size() == 2);
	prof++;
	ll ans = dfs(tr[i][0])+dfs(tr[i][1]);
	prof--;
	return ans;
}

int main() { __
	cin >> x >> n;
	priority_queue<pa> pq;
	
	tr.resize(n);
	rev.resize(n);
	for(int i = 0; i < n; i++) {
		int v;
		cin >> v;
		pq.push({-v,i});
		rev[i] = v;
	}

	while(pq.size() > 1) {
		auto [v1, i1] = pq.top();
		pq.pop();
		auto [v2,i2] = pq.top();
		pq.pop();
		// Add novo noh
		pq.push({v1+v2,tr.size()});
		tr.pb({i1,i2});
	}

	assert(pq.top().f == -x);
	cout << dfs(pq.top().s) << endl;

	exit(0);
}
