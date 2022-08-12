#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1234;

int n, m, s;

// ping, To where
vector<pair<int,int>> vec[MAX];

int dists[MAX];
int mini = INF, maxi = -INF;

// shortest distance, value -> maxqueue uses negative values
set<pair<int,int>> q;

int main() { _

	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u,v,p; 
		cin >> u >> v >> p;
		u--,v--;
		vec[u].push_back({p,v});
		vec[v].push_back({p,u});
	}
	
	cin >> s;
	s--;
	
	
	memset(dists,INF, n * sizeof(int));
	dists[s] = 0;
	q.insert({0,s});
	while(!q.empty()) {
		auto pr = *q.begin();
		q.erase(q.begin());
		int ping = pr.first, val = pr.second;
		
		assert(dists[val] == ping);
		
		if(val != s)
			mini = min(ping, mini);
		maxi = max(ping, maxi);
		
		for(auto p : vec[val]) {
			int ping2 = p.first, val2 = p.second;
			int ndist = ping + ping2;
			if(ndist < dists[val2]) {
				q.erase({dists[val2],val2});
				q.insert({ndist,val2});
				dists[val2] = ndist;
			}
		}
	}
	
	cout << maxi-mini << endl;
	exit(0);
}
