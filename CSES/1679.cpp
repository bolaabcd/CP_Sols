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

int main() { __
	int n,m;
	cin >> n >> m;
	vector<set<int>> grr(n),gr(n);
		for(int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		gr[a].insert(b);
		grr[b].insert(a);
	}
	set<int> fronter;
	vector<int> ans;
	for(int i = 0; i < n; i++)
		if(grr[i].size() == 0)
			fronter.insert(i);
	while(!fronter.empty()){
		set<int> front2;
		for(int i : fronter) {
			ans.pb(i+1);
			for(int j : gr[i]) {
				front2.insert(j);
				grr[j].erase(i);
			}
			gr[i].clear();
		}
		fronter = front2;
	};
	if(ans.size() != n) {
		cout << "IMPOSSIBLE" << endl;
		exit(0);
	}
	for(int i : ans)
		cout << i << ' ';
	cout << endl;
	exit(0);
}
