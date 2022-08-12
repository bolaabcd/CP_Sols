#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// Implementacao do Algoritmo de Dinic para fluxo maximo em redes
//
// Para usar, basta declarar com o numero de vertices
// vertices sao indexados com 0, 1, ... n-1
//
// Exemplo:
//
// dinic D(10); // teremos 10 vertices indexados de 0 a 9
// D.add(0, 1, 5); // adiciona aresta de 0 a 1 com capacidade 5
// int flow = D.max_flow(0, 1); // computa o fluxo maximo de 0 a 1

#include <vector>
#include <queue>

using namespace std;

struct dinic {
    struct edge {
        int to, cap, rev, flow;
        bool res;
        edge(int to_, int cap_, int rev_, bool res_)
            : to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
    };

    vector<vector<edge>> g;
    vector<int> lev, beg;
    long long F;
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
                lev[i.to] = lev[u] + 1;
                q.push(i.to);
            }
        }
        return lev[t] != -1;
    }
    int dfs(int v, int s, int f = 0x3f3f3f3f) {
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
    long long max_flow(int s, int t) {
		while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
        return F;
    }
};

int n;
vector<vector<pair<int,int>>> gr, gr1; // pos e peso, grafo reverso
vector<int> dists_end;

ll maxi(int distmax, dinic &copy, int k) {
    queue<pair<int,int>> vdist2; // val, dist
    vector<bool> marc2(n, false);

    vdist2.push({0,0});
    marc2[0] = true;
    while(!vdist2.empty()) {
        auto [val,dist] = vdist2.front();
        vdist2.pop();
        
        // if(marc2[val])
        //     continue;
        // marc2[val] = true;
                
        for(auto [nv, peso] : gr[val]){
            // if(dist+1+dists_end[nv] <= distmax){
            //     copy.add(val+n*k,nv+n*k,peso);
            //     // if(distmax == 2)
            //     // cout << val << ' ' << nv << endl;
            // }
            // cout << dist+1 << ' ' << distmax << endl;
            // cout << val+n*(k+dist) << ' ' << nv+n*(k+dist+1) << ' ' << peso << endl;
            copy.add(val+n*(k+dist),nv+n*(k+dist+1),peso);
            if(!marc2[nv]){
                vdist2.push({nv,dist+1});
                marc2[nv] = true;
            }
        }
    }
    int ret = copy.max_flow(0,n-1);
    return ret;
}


int main() { //_
	while(1) {
		int m,a;
		cin >> n >> m >> a;
		if(n == 0 && m == 0 && a == 0)
			break;

        dinic ans(n*300), ans2(n);
        gr.clear();
        gr.resize(n);	
        gr1.clear();
        gr1.resize(n);
		for(int i = 0; i < m; i++) {
			int o,d,s;
			cin >> o >> d >> s;
			o--;
			d--;
			gr[o].push_back({d,s});
            gr1[d].push_back({o,s});
            ans2.add(o,d,s);
		}
        queue<pair<int,int>> vdist1;
        vector<bool> marc1(n,false);
        dists_end.clear();
        dists_end.resize(n);
        vdist1.push({n-1,0});
        while(!vdist1.empty()) {
            auto [val,dist] = vdist1.front();
            vdist1.pop();
            
            if(marc1[val])
                continue;
            marc1[val] = true;
            dists_end[val] = dist;
            
            for(auto [nv, peso] : gr1[val])
                vdist1.push({nv,dist+1});
        }
        ll tot = 0;

        // ll mf = ans2.max_flow(0,n-1);

        // for(int i = 1; i < 100; i++)
        //     ans.add(0,n*i,INF);
        // for(int i = 2; i <= 100; i++)
        //     ans.add(n*i-1,n-1,INF);

        // cout << "AAAA" << endl;
        int k = 0;
        for(int d = 0; d < 101; d++) {
            // if(d >= dists_end[0])
            //     tot += mf;
            // else
            // cout << "AAAAAAAAa" << endl;
            if(d>0){
                ans.add(0,n*d,INF);
                ans.add(n*d-1,n-1,INF);
            }
            tot = maxi(d,ans,k++);
            // cout << tot << endl;
            if(tot >= a){
                cout << d-1 << endl;
                break;
            }
        }
	}
	cout << endl;
	exit(0);
}

