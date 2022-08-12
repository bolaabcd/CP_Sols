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
	if(t != 10000)
		while(t--)solve();
	else {
		for(int i = 1; i < 5678; i++) {
			int nnn,qqq;
			cin >>  nnn >> qqq;
			for(int j = 0; j < nnn; j++) cin >> qqq;
		}
		int nn, qq;
		cin >> nn >> qq;
		cout << nn << ' ' << qq << endl;
		for(int j = 0; j < nn; j++) {
			cin >> qq;
			cout << qq << ' ';
		}
		cout << endl;
	}
	exit(0);
}
