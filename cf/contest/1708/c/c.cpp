#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n,q;
	cin >> n >> q;
	vector<bool> ans(n,true);
	vector<tuple<int,int,int>> probs;
	int j = 0, bias = 0;
	for(int i = 0; i < n; i++) {
		int ai;
		cin >> ai;
		if(ai > q+bias) {
			q--;
			probs.push_back({i,ai,q+1});
		}
		if (q+bias < 0) {
			auto [pos,val,iq] = probs[j];
			ans[pos] = false;
			j++;
			bias++;
			while(j < probs.size() and get<1>(probs[j]) <= get<2>(probs[j])+bias) {
				j++;
				bias++;
			}
			//q += m;
		}
	}
	for(bool b: ans) cout << b;
	cout << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
