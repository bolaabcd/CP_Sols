#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int MOD> struct str_hash {
	static int P;
	int n;
	string s;
	vector<ll> h, power;
	str_hash(){}
	str_hash(string s_) : n(s_.size()), s(s_), h(n), power(n) {
		power[0] = 1;
		for (int i = 1; i < n; i++) power[i] = power[i-1]*P % MOD;
		h[0] = s[0];
		for (int i = 1; i < n; i++) h[i] = (h[i-1]*P + s[i]) % MOD;
	}
	ll operator()(int i, int j) { // retorna hash da substring s[i..j]
		if (!i) return h[j];
		ll ret = h[j] - h[i-1]*power[j-i+1] % MOD;
		return ret < 0 ? ret+MOD : ret;
	}
};
template<int MOD> int str_hash<MOD>::P = uniform(27, MOD-1);

str_hash h,h2;


const int MAXI = 5e3+10;
int res[MAXI][MAXI];

string s, s2;
int dp(int l,int r) {
	if(l==r) return 1;
	if(res[l][r] !=-1) return res[l][r];
//aaaa
//aaa
	ll prim = h(l,(l+r-1)/2);
	ll seg  = h2((l+r)/2+1,r);
	
	if(prim == seg) return res[l][r] = dp(l,(l+r-1)/2)+1;
	else return res[l][r] = -INF;
}
//bccb
//bcbc
int main() { _
	cin >> s;
	s2 = reverse(s.begin(),s.end());
	h = str_hash(s);
	h2 = str_hash(s2);

	for()

	exit(0);
}
