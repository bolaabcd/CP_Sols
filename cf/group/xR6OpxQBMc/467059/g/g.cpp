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

bool mark[1000];
vector<set<int>> gr;
vector<set<int>> ids;

void dfs(int i) {
	if(mark[i])
		return;
	mark[i] = true;
	for(int j : gr[i])
		dfs(j);
}

int main() { __
	int n,m;
	cin >> n >> m;
	gr.resize(n);
	ids.resize(n);
	bool corner = true;
	for(int i = 0; i < n; i++) {
		int ki;
		cin >> ki;
		for(int j = 0; j < ki; j++) {
			corner = false;
			int x;
			cin >> x;
			ids[i].insert(x-1);
		}
	}
	for(int i = 0; i <n; i++)
		for(int j = i+1; j < n; j++)
			for(int k = 0; k < m; k++)
				if(ids[i].count(k) and ids[j].count(k)) {
					gr[i].insert(j);
					gr[j].insert(i);
				}
	int amt = 0;
	for(int i = 0; i < n; i++)
		if(!mark[i]) {
			amt++;
			dfs(i);
		}
	if(corner)
		amt++;
	cout << amt -1 << endl;
	exit(0);
}
