#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n,q, inn;
	cin >> n >> q;
	deque<pair<int,int>> dq;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x == n)inn = i;
		dq.push_back({x,i});
	}
	vector<int> vics(n,0);
	vector<int> fw(n,-1);
	for(int i = 0; i < n; i++) {
		pair<int,int> a = dq.front(), b;
		dq.pop_front();
		b = dq.front();
		dq.pop_front();
		if(a.first < b.first)
			swap(a,b);
		dq.push_front(a);
		dq.push_back(b);
		vics[a.second]++;
		if(fw[a.second] == -1)
			fw[a.second] = i;
	}
	vics[inn] = INF;
	for(int j = 0; j < q; j++) {
		int i,k;
		cin >> i >> k;
		if(fw[i-1] == -1)
			cout << 0 << endl;
		else
			cout << max(0,min(k-fw[i-1],vics[i-1])) << endl;
	}
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
