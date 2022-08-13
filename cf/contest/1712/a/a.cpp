#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n,k;
	cin >> n >> k;
	vector<pair<int,int>> vec(n);// val, pos
	for(int i = 0; i < n; i++) {
		vec[i].second = i;
		cin >> vec[i].first;
	}
	sort(vec.begin(),vec.end());
	int sum = 0;
	for(int i = 0; i < k; i++) {
		sum += vec[i].second >= k;
	}
	cout << sum << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
