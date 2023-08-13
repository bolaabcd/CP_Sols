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

vector<vector<int>> gr;
stack<int> path;
set<int> found;
bool mark[112345];
void dfs(int i) {
	if(mark[i])
		return;
	mark[i] = true;
	path.push(i);
	found.insert(i);
	for(int j:gr[i])
		if(!found.count(j))
			dfs(j);
		else {
			vector<int> ans = {j};
			while(path.top() != j) {
				ans.pb(path.top());
				path.pop();
			}
			ans.pb(j);
			cout << ans.size() << endl;
			for(int k = ans.size()-1; k >= 0; k--)
				cout << ans[k]+1 << ' ';
			cout << endl;
			exit(0);
		}
	path.pop();
	found.erase(i);
}

int main() { __
	int n,m;
	cin >> n >> m;
	gr.resize(n);
	for(int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		gr[a].pb(b);
	}
	for(int i = 0; i < n; i++)
		dfs(i);
	cout << "IMPOSSIBLE" << endl;
	exit(0);
}
