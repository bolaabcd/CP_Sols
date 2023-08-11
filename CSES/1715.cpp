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

const ll MOD = 1e9+7;
const int MAX = 1e6+10;

ll fact[MAX], ifact[MAX], inv[MAX];
ll amts[26];

int main() { __
	string s;
	cin >> s;
	ll n = s.size();
	fact[0] = 1;
	for(int i = 1; i <= n; i++)
		fact[i] = (fact[i-1]*i)%MOD;
	// computa o inverso modular de 1..MAX-1 modulo um primo
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) inv[i] = MOD - MOD/i*inv[MOD%i]%MOD;
	ifact[0] = 1;
	for(int i = 1; i <= n; i++)
		ifact[i] = (inv[i]*ifact[i-1])%MOD;
	for(char c:s)
		amts[c-'a']++;
	ll tot = fact[n];
	for(int i = 0; i < 26; i++)
		tot = (tot*ifact[amts[i]])%MOD;
	cout << tot << endl;
	exit(0);
}
