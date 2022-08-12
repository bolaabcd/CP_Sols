#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n,k;
ll memo[102][102][102];
int vec[102];

ll dp(int pos, int antp, int sizat) {
    if (sizat == k)
        return 1;
    if (pos == n)
        return 0;
    if (memo[pos][antp][sizat] != -1)
        return memo[pos][antp][sizat];
    
    ll sum = dp(pos+1,antp,sizat);
    if(vec[pos] > vec[antp])
        sum += dp(pos+1,pos,sizat+1);
    return memo[pos][antp][sizat] = sum;
}

int main() { _
    while(1) {
        cin >> n >> k;
        if(n == 0 && k == 0)
            break;
        for(int i = 0; i < n; i++)
            cin >> vec[i];
        vec[101] = -INF;
        memset(memo, -1, sizeof(memo));
        cout << dp(0,101,0) << endl;
    }
    exit(0);
}

