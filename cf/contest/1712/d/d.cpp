#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int e9 = 1e9;

void solve() {
	int n,k;
	cin >> n >> k;
	vector<int> vec(n);
	for(int&i:vec)cin >> i;
	priority_queue<pair<int,int>> mins, maxs;
	if(n == k) {
		cout << e9 << endl;
		return;
	}
	for(int i = 0; i < n; i++) {
		mins.push({-vec[i],i});
	}
	for(int i = 0; i < n-1; i++) {
		maxs.push({min(vec[i],vec[i+1]),i});
	}
	set<int> del;
	for(int i = 0; i < k; i++) {
		int mini = INF, maxp = INF, mini7 = INF, maxp7 = INF;
		while(!mins.empty() and del.count(mins.top().second))
			mins.pop();
		if(!mins.empty()) {
			mini = -mins.top().first;
			int ppp = mins.top().second;
			if(!mins.empty()) {
				mins.pop();
				mini7 = -mins.top().first;
				mins.push({-mini,ppp});
			}
		}
		while(!maxs.empty() and maxs.top().first != min(vec[maxs.top().second],vec[maxs.top().second+1]))
			maxs.pop();
		if(!maxs.empty()) {
			maxp = maxs.top().first;
			int ppp = maxs.top().second;
			if(!maxs.empty()) {
				maxs.pop();
				maxp7 = maxs.top().first;
				maxs.push({maxp,ppp});
			}
		}
		int nvalmax = min(2*mini,maxp7), nvalmin = min(2*mini7,maxp);
		if(maxs.empty() or nvalmax >= nvalmin) {
			int pmax1 = maxs.top().second;
			int pmax2 = pmax1+1;
			maxs.pop();
			if(vec[pmax1] > vec[pmax2]) {
				vec[pmax2] = e9;
				del.insert(pmax2);
			} else {
				vec[pmax1] = e9;
				del.insert(pmax1);
			}
		} else {
			int pos = mins.top().second;
			vec[pos] = e9;
			del.insert(pos);
			if(pos < n-1)
				maxs.push({min(vec[pos],vec[pos+1]),pos});
			if(pos > 0)
				maxs.push({min(vec[pos],vec[pos-1]),pos-1});
		}
	}
	int mini2 = INF, maxp2 = -INF;
	
	for(int i = 0; i < n; i++) {
		mini2 = min(mini2,vec[i]);
	}
	for(int i = 0; i < n-1; i++) {
		maxp2 = max(maxp2,min(2*mini2,min(vec[i],vec[i+1])));
	}
	cout << maxp2 << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
