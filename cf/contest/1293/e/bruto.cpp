#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
vector<vector<pair<int,int>>> tree; 
vector<vector<int>> ids(3010,vector<int>(3010));

ll mex(vector<int> &foi) {
	sort(foi.begin(),foi.end());
	for(int i = 0; i < 1e10; i++)
		if( i == foi.size() || foi[i] != i) 
			return i;
}

ll dfs(int i, vector<int> foi, int pai) {
	ll soma = mex(foi);
	for(auto [j, w] : tree[i]) {
		if(j == pai)
			continue;
		foi.push_back(w);
		soma += dfs(j,foi,i);
		foi.pop_back();
	}
	return soma;
}

ll solve(vector<int> &mask) {
	for(int i = 0; i < n; i++) {
		for( auto &[j, peso] : tree[i]) {
			peso = mask[ids[i][j]];
		}
	}

	ll soma = 0;
	for(int i = 0; i < n; i++) {
		soma += dfs(i,vector<int>(),-1);
	}
	assert(soma %2 == 0);
	return soma/2;
}

int main() { _
	cin >> n;
	tree = vector<vector<pair<int,int>>>(n);

	for (int i = 0; i < n-1; i++) {
		int a,b;
		cin >> a >> b;
		tree[a-1].emplace_back(b-1,-1);
		tree[b-1].emplace_back(a-1,-1);
		ids[a-1][b-1] = i;
		ids[b-1][a-1] = i;
	}

	vector<int> mask(n-1);
	iota(mask.begin(), mask.end(), 0);

	ll maior = -LINF;
	do {
		maior = max(maior,solve(mask));
	} while(next_permutation(mask.begin(), mask.end()));

	cout << maior << endl;

	exit(0);
}
