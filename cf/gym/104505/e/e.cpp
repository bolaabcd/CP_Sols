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


int main() { __
    ll n;
    cin >> n;
    vector<vector<ll>> vec(n,vector<ll>(3));
    vector<ll> pes(n);
    ll totx = 0, toty = 0, totz = 0, spez = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) cin >> vec[i][j];
        cin >> pes[i];
        spez += pes[i];
        totx += vec[i][0] * pes[i];
        toty += vec[i][1] * pes[i];
        totz += vec[i][2] * pes[i];
    }
    
    totx /= spez;
    toty /= spez;
    totz /= spez;
    ll best = LINF, bx, by, bz;
    for(ll i = -3; i <= 3; i++)
        for(ll j = -3; j <= 3; j++)
            for(ll k = -3; k <= 3; k++) {
                ll otim = 0;
				ll vx = totx+i, vy = toty+j, vz = totz+k;
                for(int i2 = 0; i2 < n; i2++) {
					ll vvx = vec[i2][0]-vx, vvy = vec[i2][1]-vy, vvz = vec[i2][2]-vz;
                    otim += pes[i2]*(vvx*vvx+vvy*vvy+vvz*vvz);
                }
                if(otim < best) {
                    best = otim;
                    bx = vx;
                    by = vy;
                    bz = vz;
                }
            }
    cout << bx << ' ' << by << ' ' << bz << endl;
    exit(0);
}

