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
const int MAX = 1e6+10;

const ll MOD = 1e9+7;

ll fact[MAX], ifact[MAX], inv[MAX];

int main() { __
	int n;
	cin >> n;
	fact[0] = 1;
	ifact[0] = 1;
	for(int i = 1; i < MAX; i++) {
		fact[i]= (i*fact[i-1])%MOD;
		inv[i] = i==1?1:(MOD-(((MOD/i)*inv[MOD%i])%MOD))%MOD;
		ifact[i] = (inv[i]*ifact[i-1])%MOD;
	}
	for(int i	= 0; i < n; i++) {
		int a,b;
		cin >> a >> b;
		cout << (((fact[a]*ifact[b])%MOD)*ifact[a-b])%MOD << endl;
	}
	exit(0);
}
