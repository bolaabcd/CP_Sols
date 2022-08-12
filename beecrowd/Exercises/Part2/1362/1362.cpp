#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// Dinic
//
// O(min(m * max_flow, n^2 m))
// Grafo com capacidades 1 -> O(sqrt(n)*m)
// 67ce89

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
	    //cout << a << ' ' << b << ' '<<c<<endl;
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

// Recupera as arestas do corte s-t
// d23977
vector<pair<int, int>> get_cut(dinic& g, int s, int t) {
	g.max_flow(s, t);
	vector<pair<int, int>> cut;
	vector<int> vis(g.g.size(), 0), st = {s};
	vis[s] = 1;
	while (st.size()) {
		int u = st.back(); st.pop_back();
		for (auto e : g.g[u]) if (!vis[e.to] and e.flow < e.cap)
			vis[e.to] = 1, st.push_back(e.to);
	}
	for (int i = 0; i < g.g.size(); i++) for (auto e : g.g[i])
		if (vis[i] and !vis[e.to] and !e.res) cut.emplace_back(i, e.to);
	return cut;
}

int main() { _
    int ttt;
    cin >> ttt;
    while(ttt--) {
        int n,m;//m sao as pessoas!
        cin >> n >> m;
        dinic fluxo(2+n+m);
        
        map<string,int> init = {{"XS",2+m},{"XXL",2+m+n/6},{"XL",2+m+n/3},{"L",2+m+n/2},{"M",2+m+2*n/3},{"S",2+m+5*n/6}};
        //cout << 2+m+n/2 << endl;
        for(int i = 2; i <= m+1; i++)
        	fluxo.add(0,i,1);
        for(int i = m+2; i<= m+n+1; i++)
        	fluxo.add(i,1,1);
        for(int i = 0; i < m; i++) {
        	string f,s;
        	cin >> f >> s;
        	//cout << f << ' ' << s << endl;
        	for (int j = 0; j < n/6; j++)
        	    fluxo.add(2+i,j+init[f],1);
        	for (int j = 0; j < n/6; j++)
        	    fluxo.add(2+i,j+init[s],1);
        }
        
        int mf = fluxo.max_flow(0,1);
        assert(mf <= m);
        if(mf == m)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;    
    }
    
    exit(0);
}


