#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n,m;
	cin >> n >> m;
	bool mat[n][m];
	int sx,sy,ex,ey;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			char x;
			cin >> x;
			switch(x) {
				case '#':
				mat[i][j] = false;
				break;
				case '.':
				mat[i][j] = true;
				break;
				case 'A':
				sx = i;
				mat[i][j] = true;
				sy = j;
				break;
				default:
				ex = i;
				mat[i][j] = true;
				ey = j;
			}
		}
	int dist[n][m];
	pair<int,int> ant[n][m];
	char antt[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			dist[i][j] = mat[i][j] ? INF: -INF;
			ant[i][j] = {-2,-2};
			antt[i][j] = 'X';
		}
	queue<pair<int,int>> q;
	q.push({sx,sy});
	dist[sx][sy] = 0;
	ant[sx][sy] = {-1,-1};
	while(!q.empty()) {
		auto [x,y] = q.front();
		q.pop();
		if(x+1 < n and dist[x+1][y] > dist[x][y]+1) {
			dist[x+1][y] = dist[x][y]+1;
			ant[x+1][y] = {x,y};
			antt[x+1][y] = 'D';
			q.push({x+1,y});
		}
		if(x-1 >= 0 and dist[x-1][y] > dist[x][y]+1) {
			dist[x-1][y] = dist[x][y]+1;
			ant[x-1][y] = {x,y};
			antt[x-1][y] = 'U';
			q.push({x-1,y});
		}
		if(y+1 < m and dist[x][y+1] > dist[x][y]+1) {
			dist[x][y+1] = dist[x][y]+1;
			ant[x][y+1] = {x,y};
			antt[x][y+1] = 'R';
			q.push({x,y+1});
		}
		if(y-1 >= 0 and dist[x][y-1] > dist[x][y]+1) {
			dist[x][y-1] = dist[x][y]+1;
			ant[x][y-1] = {x,y};
			antt[x][y-1] = 'L';
			q.push({x,y-1});
		}
	}
	if(ant[ex][ey].f == -2)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		vector<char> ans;
		int cx = ex, cy = ey;
		while(cx != -1) {
			ans.push_back(antt[cx][cy]);
			int tmpcx = cx;
			cx = ant[cx][cy].f;
			cy = ant[tmpcx][cy].s;
		}
		cout << ans.size()-1 << endl;
		for(int i = ans.size()-2; i >= 0; i--)
			cout << ans[i];
		cout << endl;
	}
	exit(0);
}
