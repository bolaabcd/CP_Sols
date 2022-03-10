#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll pow(ll x, ll y, ll m) { // iterativo
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return ret;
}

const ll MOD = 1e9+7;

int main() { _
	string s;
	cin >> s;
	ll am = 0;
	ll tot = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'a')
			am++;
		else
			tot = (pow(2,am,MOD) -1 + tot)%MOD;
	}
	cout << tot << endl;
	exit(0);
}
