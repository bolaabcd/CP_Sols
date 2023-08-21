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
const int MOD = 1e9+7;

int main() { __
	ll n, x;
	cin >> n >> x;
	vector<ll> vec(n);
	for(ll&i:vec)cin>>i;
	ll dp[100+10][5000+10];// dp(i,x) = ateh i , <= x
	for(int j = 0; j <= x; j++)
		dp[0][j] = 1;

	for(int j = 1; j <= x; j++)
		for(int i = 1; i <= n; i++) {
			dp[i][j] = 0;
			for(int k = i; k >= 1; k--) {
				if(x-dif >= 0) {
					ll dif = vec[i]-vec[k];
					dp[i][j] += dp[k-1][x-dif]+dif;
					dp[i][j] %= MOD;
				}
			}
		}
	cout << dp[n][x] << endl;
	exit(0);
}
