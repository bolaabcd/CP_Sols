#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> gr;
vector<vector<int>> gr2;

void dfs_clean(int r,int p) {
	if(p != -1)
		gr2[p].push_back(r);
	for(int i:gr[r])
		if(i != p)
			dfs_clean(i,r);
}

void dfs(int r, bool inv) {
	for(int i = inv; i < gr2[r].size(); i += 2)
		dfs(gr2[r][i],false);	
	cout << r << ' ';
	for(int i = !inv; i < gr2[r].size(); i +=2)
		dfs(gr2[r][i],true);
}

int main() { 
	int n;
	cin >> n;
	gr.resize(n);
	gr2.resize(n);
	for(int i = 0; i < n-1; i++) {
		int a,b;
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs_clean(0,-1);
	dfs(0,false);
	cout << endl;
	exit(0);
}
