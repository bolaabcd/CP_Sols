#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n,m;
	cin >> n >> m;
	vector<vector<char>> mat(n,vector<char>(m));
	int num = 0;
	bool z2 = false, z1 = false;
	for(auto&v:mat)
		for(auto&i:v) {
			cin >> i;
			num += i == '1';
			if(i == '0')
				z1 = true;
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m-1; j++) 
			if(mat[i][j] == '0' and mat[i][j+1] == '0')
				z2 = true;
	for(int i = 0; i < n-1; i++)
		for(int j = 0;j < m; j++)
			if(mat[i][j] == '0' and mat[i+1][j] == '0')
				z2 = true;
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < m-1; j++)
			if(mat[i][j] == '0' and mat[i+1][j+1] == '0')
				z2 = true;
	for(int i = 0; i < n-1; i++)
		for(int j = 1; j < m; j++)
			if(mat[i][j] == '0' and mat[i+1][j-1] == '0')
				z2 = true;

	if(z2)
		cout << num << endl;
	else if(z1)
		cout << num-1 << endl;
	else
		cout << num-2 << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
