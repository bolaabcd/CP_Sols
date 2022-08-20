#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<tuple<int,int,int>> tp;
vector<int> ans, tmp;
int n, q;

void solve(int i) {
	if(i == n) {
		if(tmp >= ans)
			return;
		for(auto [p,j,x] : tp)
			if((tmp[p] | tmp[j]) != x)
				return;
		ans = tmp;
		return;
	}
	solve(i+1);
	tmp[i] = 1;
	solve(i+1);
	tmp[i] = 0;
}

int main() { _
	cin >> n >> q;
	ans.resize(n,1);
	tmp.resize(n,0);
	tp.resize(q);
	for(auto &[i,j,x] : tp) {
		cin >> i >> j >> x;
		i--;
		j--;
		if(i > j)
			swap(i,j);
	}
	solve(0);
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	exit(0);
}
