#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll as[3][ll(3e5)], arr[ll(3e5)];

int n,m;
ll getamt(ll* a1, ll* a2) {
	//cout << a1[6] << ' ' << a2[6] << endl;
	ll pos = 0, nexts = 0;
	for(int i = 0; i < m; i++) {
		ll x = a1[i]-a2[i]+nexts;
		//cout << a1[i] << ' ' << a2[i] << ' ' << x << ' ' << pos << endl;
		nexts = 0;
		if(x == 0)
			continue;
		assert(i < m-1);
		pos += x;
		nexts = x;
	}
	return abs(pos);
}

int findesp() {
	ll zu = getamt(as[0],as[1]), zd = getamt(as[0],as[2]), ud = getamt(as[1],as[2]);
	if(zu > 0 and ud == 0)
		return 0;
	if(ud > 0 and zd == 0)
		return 1;
	if(zd > 0 and zu == 0)
		return 2;

	assert(zu == 0 and zd == 0 and ud == 0);
	return -1;
}

void solve() {
	cin >> n >> m;
	int i;
	for(i = 0; i < 3; i++)
		for(int j = 0; j < m; j++)
			cin >> as[i][j];
	int esp = findesp();
	//cout << esp << endl;
	if(esp != -1)
		cout << esp+1 << ' ' << getamt(as[esp],as[(esp+1)%3]) << endl;
	else {
		for(; i < n; i++) {
			for(int j = 0; j < m; j++)
				cin >> arr[j];
			ll amt = getamt(arr,as[0]);
			if(amt != 0) {
				i++;
				cout << i << ' ' <<  amt << endl;
				break;
			}
		}
	}
	for(; i < n; i++)
		for(int j = 0; j < m; j++) {
			ll x;
			cin >> x;
		}
}

int main() { //_
	int t;
	cin >> t;
	while(t--)
		solve();
	exit(0);
}
