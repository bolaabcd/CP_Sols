#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<tuple<int,ll,ll>>> tr;

vector<ll> sums, pref;

vector<int> ans;

void dfss(int i) {
	for(auto [j,a,b]: tr[i]) {
		sums[j] = sums[i] + a;
		dfss(j);
	}
}

void dfsp(int i) {
	if(i != 0) {
		int l = 0, r = pref.size()-1;
		if(pref[0] <= sums[i]) {
			while (l!=r) {
				int mid = (l+r+1)/2;
				if(pref[mid] <= sums[i])
					l = mid;
				else
					r = mid-1;
			}
			ans[i] = l;
		} else {
			ans[i] = 0;
		}
	}
	for(auto [j,a,b] : tr[i]) {
		pref.push_back(pref.back()+b);
		dfsp(j);
		pref.pop_back();
	}
}

void solve() {
	int n;
	cin >> n;
	tr.clear();
	tr.resize(n);
	for(int j = 2; j <= n; j++) {
		int pj,aj,bj;
		cin >> pj >> aj >> bj;
		tr[pj-1].push_back({j-1,aj,bj});
	}
	sums.clear();
	sums.resize(n,0);
	dfss(0);
	ans.clear();
	ans.resize(n, 0);
	pref.clear();
	pref.push_back(0LL);
	dfsp(0);
	for(int i = 1; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
