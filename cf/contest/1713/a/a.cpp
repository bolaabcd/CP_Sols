#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n;
	cin >> n;
	int a = 0,b = 0,c = 0,d = 0;
	for(int i = 0; i < n; i++) {
		int x,y;
		cin >> x >> y;
		a = min(a,x);
		b = min(b,y);
		c = max(c,x);
		d = max(d,y);
	}
	cout << 2*(abs(a)+abs(b)+abs(c)+abs(d)) << endl;
	
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
