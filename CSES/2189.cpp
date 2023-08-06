#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	ll x1,y1,x2,y2,x3,y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if(!((x2-x1)*(y3-y1) - (y2-y1)*(x3-x1)))
		cout << "TOUCH" << endl;
	else if((x2-x1)*(y3-y1) - (y2-y1)*(x3-x1) > 0) // (p2-p1) x (p3-p1), ad-bc
		cout << "LEFT" << endl;
	else
		cout << "RIGHT" << endl;
}

int main() { __
	int t;
	cin >> t;
	while(t--)
		solve();
	exit(0);
}
