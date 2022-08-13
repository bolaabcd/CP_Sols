#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve () {
	int n;
	cin >> n;
	vector<pair<int,int>> vec(n,{INF,-INF});
	vector<int> orig(n);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		orig[i] = x;
		x--;
		vec[x].first = min(vec[x].first,i);
		vec[x].second = max(vec[x].second,i);
	}
	int lim = -1;
	int prevmax = vec[0].second;
	for(int i = 1; i < n; i++) {
		if(vec[i].first == INF)
			continue;
		if(vec[i].first < prevmax) {
			lim = prevmax-1;
		}
		prevmax = max(vec[i].second,prevmax);
	}
	set<int> nn;
	for(int i = 0; i <= lim; i++)
		nn.insert(orig[i]);
	cout << nn.size() << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
