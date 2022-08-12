#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 40;

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

int pts[MAX];
int ars_falt[MAX][MAX];

int main() { _
	while(1) {
		int n,m,g;
		cin >> n >> m >> g;
		int npts = n*(n-1)*m*2;
		if(n == 0 && m == 0 && g == 0)
			break;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				ars_falt[i][j] = m;
			pts[i] = 0;
		}

		for(int i = 0; i < g; i++) {
			int ii,j;
			char c;
			cin >> ii >> c >> j;
			ars_falt[ii][j]--;
			ars_falt[j][ii]--;
			if(c == '<') {
				pts[j] += 2;
			} else if (c == '>') {
				pts[ii] += 2;
			} else {
				pts[ii]++;
				pts[j]++;
			}
			npts -= 2;
		}
		for(int j = 0; j < n; j++) {
			pts[0] += 2*ars_falt[0][j];
			npts -= 2*ars_falt[0][j];
			assert(ars_falt[0][j] == ars_falt[j][0]);
			ars_falt[0][j] = 0;
			ars_falt[j][0] = 0;
		}

		dinic ans(2+2*n+(n+1)*(n-1));
		for(int i = 1; i < n; i++){
			ans.add(0,2+i,INF);
			ans.add(2+n+i,1,max(pts[0]-pts[i],0));
		}
		for(int i = 1; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				assert(ars_falt[i][j] == ars_falt[j][i]);
				ans.add(2+i        , 2+2*n+n*i+j, m*ars_falt[i][j]);
				ans.add(2+j        , 2+2*n+n*i+j, m*ars_falt[i][j]);
				ans.add(2+2*n+n*i+j, 2+n+i      , 2*m*ars_falt[i][j]);
				ans.add(2+2*n+n*i+j, 2+n+j      , 2*m*ars_falt[i][j]);
			}
		}

		int mf = ans.max_flow(0,1);
		assert(mf >= 0);
		assert(mf <= npts);
		if(mf == npts)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
	exit(0);
}
