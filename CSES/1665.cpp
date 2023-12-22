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

ll dp[100+10][5000+10]; // dp(..i,<=x)
int main() { __
    ll n, x;
    cin >> n >> x;
    vector<ll> vec(n);
    for(ll&i:vec)cin>>i;
    sort(vec.begin(),vec.end());

    for(int j = 0; j <= x; j++)
        dp[0][j] = 1; // 1 forma com 1 elemento soh
    for(int i = 1; i < n; i++) // ..i
        for(int j = 0; j <= x; j++) { // <= j
            dp[i][j] += dp[i-1][j]; // parar no proprio i, 0 a mais no custo
            dp[i][j] %= MOD;
            for(int k = i-1; k >= 0; k--) {
                ll dif = vec[i]-vec[k];
                if (j - dif >= 0) {
                    if(k-1 >= 0)
                        dp[i][j] += dp[k-1][j-dif];
                    else
                        dp[i][j] += 1; // 1 forma sem nenhum grupo
                    dp[i][j] %= MOD;
                }
            }
        }

    cout << dp[n-1][x] << endl;
    exit(0);
}
