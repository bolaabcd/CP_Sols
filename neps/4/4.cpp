#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n,m;
	cin >> n >> m;
	ll ant = -1, tot = 0;
	for(int i = 0; i < n; i++) {
		int v, w;
		cin >> v;
		w = m - v;
		if(v < ant && w < ant){
			cout << -1 << endl;
			return 0;
		} else if(min(w,v) >= ant) {
			v = min(w,v);
		} else {
			v = max(w,v);
		}
		ant = v;
		tot += v;
	}
	cout << tot << endl;
	exit(0);
}
