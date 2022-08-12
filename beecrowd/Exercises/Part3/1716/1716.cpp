#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int lim = 1e9+1;

ll powmod(ll c, ll d, ll n) { // c^d mod n
	ll ans = 1;
	c %= n;
	while(d > 0) {
		if(d%2)
			ans = (c*ans)%n;
		d /= 2;
		c = (c*c)%n;
	}
	return ans;
}

pair<ll,ll> eucex(ll q1, ll q2, ll r1, ll r2, ll u1, ll u2, ll v1, ll v2) {// euclides extendido, retorna u tal que ue - xn = 1 (calcula x tbm mas nao usa)
	if(r2 == 1)
		return {u2,v2};
	ll q3 = r1/r2;
	return eucex(q2, q3, r2, r1%r2, u2, u1-u2*q3, v2, v1-v2*q3);
}

int main() { _
	ll n,e,c, p = 0, q = -1;
	cin >> n >>e >> c;
	
	// marcando primos até 10^5
	vector<bool> prims(lim,true);
	prims[0] = false;
	prims[1] = false;
	for (ll i = 2; i*i <= lim; i++) {
		if(!prims[i])
			continue;
		if((n%i == 0) && !p)
			p = i, q = n/i;
		for (ll j = i+i; j*j < lim; j += i)
			prims[j] = false;
	}

	ll fi = (p-1)*(q-1);
	auto pa = eucex(0, 0, fi, e, 1, 0, 0, 1);
	if(pa.s < 0) pa.s += fi, pa.f -= e;
	ll d = abs(pa.s);
	cout << powmod(c, d, n) << endl;


	exit(0);
}


