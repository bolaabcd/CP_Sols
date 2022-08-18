#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 3e5+100;

int vec[MAX];
int dp[MAX];
int n;
vector<pair<int,int>> od[201][201];
int find(int pos) {
	int ans = -INF;
	for(int aj = 0; aj <= 200; aj++) {
		/*int l = 0, r = od[aj][vec[pos]].size();
		while(l != r) {
			int mid = (l+r)/2;
			if(od[aj][vec[pos]][mid].first > (aj^pos))
				r = mid;
			else
				l = mid+1;
		}
		if(l == od[aj][vec[pos]].size())
			continue;
		*/
		if(od[aj][vec[pos]].empty() or od[aj][vec[pos]].back().first <= (aj^pos))
			continue;
		ans = max(ans,od[aj][vec[pos]].back().second);
	}
	if(ans == -INF)
		return n;
	return ans;
}

void solve() {
	cin >> n;
	dp[n] = 0;
	for(int i = 0; i <= 200; i++)
		for(int j = 0; j <= 200; j++)
			od[i][j].clear();
	for(int i = 0; i < n; i++) {
		dp[i] = 1;
		cin >> vec[i];
		if(i > 0)
			dp[i] = dp[find(i)]+1;
		for(int aj = 0; aj <= 200; aj++) {
			od[vec[i]][aj].push_back({i^aj,i});
		}
		for(int j = 0; j <= 200; j++)
			sort(od[vec[i]][j].begin(),od[vec[i]][j].end());
	}
	//for(int i = 0; i <= 200; i++)
	//	for(int j = 0; j <= 200; j++)
	//		sort(od[i][j].begin(),od[i][j].end());
	//for(int p = 1; p < n; p++) {
	//	dp[p] = max(dp[p-1], dp[find(p)]+1);
	//}
	int maxi = -INF;
	for(int i = 0; i < n; i++)
		maxi = max(maxi,dp[i]);
	cout << maxi << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
