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
const int MAX = 6e5;

// Aho-corasick 
//
// query retorna o somatorio do numero de matches de
// todas as stringuinhas na stringona
//
// insert - O(|s| log(SIGMA))
// build - O(N), onde N = somatorio dos tamanhos das strings
// query - O(|s|)

namespace aho {
	map<char, int> to[MAX];
	int link[MAX], idx, term[MAX], exit[MAX], sobe[MAX], marca[MAX], resp[MAX];
	// acho que term marca quantas strings terminam ali
	vector<int> fins[MAX], rlink[MAX];

	void insert(string& s, int pos) {
		int at = 0;
		for (char c : s) {
			auto it = to[at].find(c);
			if (it == to[at].end()) at = to[at][c] = ++idx;
			else at = it->second;
		}
		term[at]++, sobe[at]++;
		fins[at].pb(pos);
	}
	bool mark[MAX];
	int dfs(int i) {
		if(mark[i])
			return resp[i];
		mark[i] = true;
		int ans = marca[i];
		for(int j:rlink[i])
			ans += dfs(j);
		return resp[i] = ans;
	}
	void printa(int n) {
		vector<int> ans(n);
		//for(int i = 0; i < MAX; i++)
		//	if(marca[i])
		dfs(0);
		for(int i = 0; i < MAX; i++)
			if(term[i])
				for(int j : fins[i])
					ans[j] = resp[i];
		for(int i:ans)
			cout << i << endl;
	}
//#warning nao esquece de chamar build() depois de inserir
	void build() {
		queue<int> q;
		q.push(0);
		link[0] = exit[0] = -1;
		while (q.size()) {
			int i = q.front(); q.pop();
			for (auto [c, j] : to[i]) {
				int l = link[i];
				while (l != -1 and !to[l].count(c)) l = link[l];
				link[j] = l == -1 ? 0 : to[l][c];
				rlink[link[j]].pb(j);
				exit[j] = term[link[j]] ? link[j] : exit[link[j]];
				if (exit[j]+1) sobe[j] += sobe[exit[j]];
				q.push(j);
			}
		}
	}
	int query(string& s) {
		int at = 0, ans = 0;
		for (char c : s){
			while (at != -1 and !to[at].count(c)) at = link[at];
			at = at == -1 ? 0 : to[at][c];
			ans += sobe[at];
			marca[at]++;
			//cout << at << ' ';
		}
		//cout << endl;
		return ans;
	}
}

int main() { __
	string s;
	cin >> s;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string t;
		cin >> t;
		aho::insert(t,i);
	}
	aho::build();
	aho::query(s);
	
	aho::printa(n);

	exit(0);
}
