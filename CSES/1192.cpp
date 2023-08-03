#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool mat[1001][1001];

void dfs(int i, int j) {
	if(i < 0 or j < 0 or i > 1000 or j > 1000 or !mat[i][j])
		return;
	mat[i][j] = false;
	dfs(i+1,j);
	dfs(i-1,j);
	dfs(i,j+1);
	dfs(i,j-1);
}

int main() { _
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			char x;
			cin >> x;
			if(x == '.')
				mat[i][j] = true;
		}
	
	int amt = 0;
	for(int i = 0; i < 1001; i++)
		for(int j = 0; j < 1001; j++)
			if(mat[i][j]) {
				amt++;
				dfs(i,j);
			}
	
	cout << amt << endl;
	exit(0);
}
