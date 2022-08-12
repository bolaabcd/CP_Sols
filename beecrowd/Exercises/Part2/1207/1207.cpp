#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct dinic {
	const bool scaling = false;
	int lim;
	struct edge {
		int to, cap, rev, flow;
		bool res;
		edge(int to_, int cap_, int rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<int> lev, beg;
	ll F;
	dinic(int n) : g(n), F(0) {}

	void add(int a, int b, int c) {
		g[a].emplace_back(b, c, g[b].size(), false);
		g[b].emplace_back(a, 0, g[a].size()-1, true);
	}
	bool bfs(int s, int t) {
		lev = vector<int>(g.size(), -1); lev[s] = 0;
		beg = vector<int>(g.size(), 0);
		queue<int> q; q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto& i : g[u]) {
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}
		return lev[t] != -1;
	}
	int dfs(int v, int s, int f = INF) {
		if (!f or v == s) return f;
		for (int& i = beg[v]; i < g[v].size(); i++) {
			auto& e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			int foi = dfs(e.to, s, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
		return F;
	}
};

int amts[450];
int main() { _
	while(1) {
		// vodka and benefits
		int n, m;
		cin >> n >> m;
		if(cin.eof())
			break;
		dinic ans(n+m+2); // 0 = s, 1 = t
		for(int i = 0; i < n; i++) {
			int val;
			cin >> val;
			ans.add(2+m+i,1,val);
			// source -> m benefits -> n vodkas -> destiny
		}

		for(int i = 0; i < m; i++) {
			cin >> amts[i];
		}
		int sbel = 0;
		for(int i = 0; i < m; i++) {
			int bel;
			cin >> bel;
			sbel += bel;
			ans.add(0,2+i,bel);
			for(int j = 0; j < amts[i]; j++) {
				int dest;
				cin >> dest;
				ans.add(2+i,2+m+dest-1,INF);
			}
		}

		cout << sbel - ans.max_flow(0,1) << endl;
	}
	exit(0);
}
