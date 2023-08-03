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
const int MAX = 501, MOD = 1e9+7;

string s;
ll mem[MAX][MAX];
ll bin[MAX][MAX];

ll dp(int l, int r) {
	if(r+1 == l)
		return s[l] == s[r];
	if(r < l or (r-l+1)%2)
		return 0;
	if(mem[l][r]+1)
		return mem[l][r];
	ll tot = 0;
	if(s[l] == s[r]) {
		tot += dp(l+1,r-1);
		tot %= MOD;
	}
	for(int i = l+1; i+1 < r; i++)
		if(s[l] == s[i]) {
			tot += (((dp(l+1,i-1)*dp(i+1,r))%MOD)*bin[(r-l+1)/2][(i-l+1)/2])%MOD;
			tot %= MOD;
		}
	return mem[l][r] = tot%MOD;
}

int main() { __
	memset(mem,-1,sizeof mem);
	for(int a = 0; a < MAX; a++)
		bin[a][0] = bin[a][a] = 1;
	for(int a = 1; a < MAX; a++)
		for(int b = 1; b < a; b++)
			bin[a][b] = (bin[a-1][b-1]+bin[a-1][b])%MOD;
	cin >> s;
	cout << dp(0,s.size()-1) << endl;
	exit(0);
}
