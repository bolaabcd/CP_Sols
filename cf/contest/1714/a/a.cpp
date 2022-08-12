#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n,h,m,hm;
	cin >> n >> h >> m;
	hm = h*60+m;
	vector<int> tms(n);
	for(int i = 0; i < n; i++) {
		int x,y;
		cin >> x >> y;
		tms[i] = x*60+y;
	}
	sort(tms.begin(),tms.end());
	int mins = INF;
	for(int i = 0; i < n; i++) {
		mins = min(mins,(tms[i]-hm+60*24)%(24*60));
	}
	cout << mins/60 << ' ' << mins%60 << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
