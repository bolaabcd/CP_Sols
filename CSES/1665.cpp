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
	sort(vec.begin(),vec.end());
	ll dp[100+10][5000+10];// dp(i,x) = ateh i , <= x
	for(int j = 0; j <= x; j++)
		dp[0][j] = 1; // sem ngm eh <= tudo

	for(int i = 1; i <= n; i++) 
		for(int j = 0; j <= x; j++) {
			dp[i][j] = 0;
			for(int k = i; k >= 1; k--) {
				ll dif = vec[i-1]-vec[k-1];
				if(j-dif >= 0) {
					dp[i][j] += dp[k-1][j-dif];
					dp[i][j] %= MOD;
				}
			}
		}
	cout << dp[n][x] << endl;
	exit(0);
}
