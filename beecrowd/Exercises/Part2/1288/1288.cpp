#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll pows[101], weis[101];
ll n, r, k;

ll memo[101][101];

ll dp(ll p,ll cap) {
//cout << p <<' '<< cap << endl;
    if (cap < 0)
        return -LINF;
    if (p == n)
        return 0;
    if(memo[p][cap] != -1)
        return memo[p][cap];
    return memo[p][cap] = max(dp(p+1,cap),dp(p+1,cap-weis[p])+pows[p]);
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> pows[i] >> weis[i];
    cin >> k >> r;
    memset(memo, -1, sizeof(memo));
    //cout <<  dp(0,k)<< endl;
    if (dp(0,k) >= r)
        cout << "Missao completada com sucesso" << endl;
    else
        cout << "Falha na missao" << endl;
}

int main() { _
    int ttt;
    cin >> ttt;
    while(ttt--)
    	solve();
    exit(0);
}

