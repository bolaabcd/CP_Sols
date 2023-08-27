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
const ll LINF = 0x3f3f3f3f3f3f3f3f;


const ll MOD = 1e9+7;

ll inv(ll a, ll b = MOD) {
	return a > 1? b-inv(b%a, a)*b/a : 1;
}

ll pow(ll x, ll y, ll m) {
	ll ret = 1;
	while(y) {
		if(y&i) ret = (ret*x)%m;
		y >>= 1;
		x = (x*x)%m;
	}
	return ret;
}

int MAX = 2e5+10;
ll inve[MAX];
ll fact[MAX];
ll ifact[MAX];

ll binom(int a, int b) {// a escolhe b
	return (((fact[a]*ifact[b])%MOD)*ifact[a-b])%MOD;
}
ll n,k;
ll gn[MAX];

int main() { __
	inve[1] = 1;
	for(int i = 2;i < MAX; i++) inv[i] = MOD-MOD/i*inve[MOD%i]%MOD;
	fact[0] = 1;
	ifact[0] = 1;
	for(int i = 1; i < MAX; i++) {
		fact[i] = (i*fact[i-1])%MOD;
		ifact[i] = (inve[i]*ifact[i-1])%MOD
	}
	cin >> n >> k;
	gn[0] = n;
	gn[1] = ((n*(n+1))/2)%MOD;
	for(int kk = 2; kk <= k; kk++) {
		gn[kk] = (inv(k+1)*((pow(n,k+1)+)%MOD))%MOD
	}
	ll tot = gn[k];
	for(int i = 0; i <= k; i++) {
		tot += ;
	}
	ll val = 0;
	
    exit(0);
}
