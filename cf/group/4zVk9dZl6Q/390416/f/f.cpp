#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n,k,m;

vector<vector<pair<int,int>>> gr;//pra onde, peso

int mem[81][81][81][81];
int mem2[81][81][2];

int dp(int p, int l,int r,int ka) {
	if(ka == 1)
		return 0;
	if (l >= r)
		return INF;
	if(mem[p][l][r][ka] != -1)
		return mem[p][l][r][ka];
	int mini = INF;
	for(int i = 0; i < gr[p].size(); i++) {
		int j = gr[p][i].first, w = gr[p][i].second;
		if(j < l or j > r)
			continue;
		mini = min(mini,dp(j,l,j,ka-1)+w);
		mini = min(mini,dp(j,j,r,ka-1)+w);
	}
	return mem[p][l][r][ka] = mini;
}
/*
int od(int p, int ka, int dir) {
	if(ka == 1)
		return 0;
	if(mem2[p][ka][dir == -1] != -1)
		return mem2[p][ka][dir == -1];
	int mini = INF;
	for(int i = 0; i < gr[p].size(); i++) {
		int j = gr[p][i].first, w = gr[p][i].second;
		if((j-p < 0) != (dir <0))
			continue;
		mini = min(mini,od(j,ka-1,dir)+w);
		mini = min(mini,dp(j,min(j,p)+1,max(j,p)-1,ka-1)+w);
	}
	return mem2[p][ka][dir == -1] = mini;
}
*/
int main() { _
	memset(mem,  -1, sizeof(mem));
	memset(mem2, -1, sizeof(mem2));
	cin >> n >> k;
	cin >> m;
	gr.resize(n);
	for(int i = 0; i < m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		//if(u == v) continue;
		u--;
		v--;
		gr[u].push_back({v,w});
	}
	int mini = INF;
	for(int i = 0; i < n; i++) {
		mini = min(mini,dp(i,i,n-1,k));
		mini = min(mini,dp(i,0,i,k));
		//mini = min(mini,od(i,k,1));
		//mini = min(mini,od(i,k,-1));
	}

	if(mini == INF)
		cout << -1 << endl;
	else
		cout << mini << endl;
	exit(0);
}
