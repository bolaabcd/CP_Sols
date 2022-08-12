#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9+7;
const int MAX = 1e6+100;

ll fact[MAX], ifact[MAX];

ll binom(int a, int b) { // a choose b
	if(a < b) return 0;
	return (((fact[a]*ifact[a-b])%MOD)*ifact[b])%MOD;
}

ll inv(ll val) {
	ll ans = 1, cop = MOD-2;
	while(cop > 0) {
		if(cop%2) ans *= val;
		cop /= 2;
		val *= val;
		val %= MOD;
		ans %= MOD;
	}
	return ans;
}

int main() { _
	fact[0] = 1;
	for(int i = 1; i < MAX; i++) 
		fact[i] = (fact[i-1]*i)%MOD;
	ifact[MAX-1] = inv(fact[MAX-1]);//inverso modular do fatorial de 2e5+99
	for(int i = MAX-2; i >= 0; i--) {
		ifact[i] = (ifact[i+1]*(i+1))%MOD;
	}
	
	int n;
	cin >> n;
	ll tot = 0;
	for(int i = 0; i <= n; i++) {
		ll v;
		cin >> v;
		tot = (tot+binom(v+i,i+1))%MOD;
	}

	cout << tot << endl;

	exit(0);
}
