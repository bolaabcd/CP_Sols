#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 26+4;


bool marc[MAX];
vector<vector<int>> graph;

void dfs(int i, vector<int>& comp) {
	if(marc[i])
		return;
	marc[i] = true;
	comp.push_back(i);
	for(int& v: graph[i])
		dfs(v,comp);
}

int main() { _
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		int v,e;
		cin >> v >> e;
		memset(marc,false, sizeof marc);
		graph.clear();
		graph.resize(v,vector<int>());

		cout << "Case #" << tc << ":"<< endl;

		for(int i = 0; i < e; i++) {
			char a,b;
			cin >> a >> b;
			a-='a';
			b-='a';
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		vector<vector<int>> ccs;
		for(int i = 0; i < v; i++) {
			if(!marc[i]) {
				ccs.push_back(vector<int>());
				dfs(i,ccs.back());
				sort(ccs.back().begin(), ccs.back().end());
			}
		}

		sort(ccs.begin(), ccs.end(),[&](auto& l, auto& r) {
			return l[0] < r[0];
		});

		for(auto& comp: ccs){
			for(int i: comp){
				assert(i+'a' >= 'a' && i+'a' <='z');
				cout << char(i+'a') << ',';
			}
			cout << endl;
		}

		cout << ccs.size() <<" connected components" << endl << endl;

	}
	exit(0);
}
