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

vector<int> gr[2500];
bool mark[2500];
int dist[2500], pa[2500];

int main() { __
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	int ans = INF;
	for(int i = 0; i < n; i++) {
		memset(mark,false,sizeof mark);
		memset(dist,INF,sizeof dist);
		memset(pa,-1,sizeof pa);
		queue<int> q;
		q.push(i);
		mark[i] = true;
		dist[i] = 0;
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			for(int y : gr[x])
				if(pa[x] != y) {
					if(!mark[y]) {
						mark[y] = true;
						dist[y] = dist[x]+1;
						pa[y] = x;
						q.push(y);
					} else
						ans = min(ans,dist[x]+1+dist[y]);
				}
		}
	}
	if(ans == INF)
		cout << -1 << endl;
	else
		cout << ans << endl;
	exit(0);
}
