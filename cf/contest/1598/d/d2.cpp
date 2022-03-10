#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

void debug_out(string s, int line) { cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t) {
    if (s[0] != ',') cerr << "Line(" << line << ") ";
    do { cerr << s[0]; s = s.substr(1);
    } while (s.size() and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}
#ifdef DEBUG
#define debug(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
#define debug(...)
#endif

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> tops(n);
        vector<ll> difs(n);
        set<ll> diftops;
        set<ll> difdifs;
        multiset<ll> diftopsms;
        multiset<ll> difdifsms;
        set<pair<ll,ll>> allDif;
        map<ll,set<ll>> dificDif;
        map<ll,set<ll>> dificTop;
        for(ll i =0; i < n; i++) {
            cin >> tops[i] >> difs[i];
            diftops.insert(tops[i]);
            difdifs.insert(difs[i]);
            diftopsms.insert(tops[i]);
            difdifsms.insert(difs[i]);
            allDif.emplace(tops[i],difs[i]);
            dificDif[tops[i]].insert(difs[i]);
            dificTop[difs[i]].insert(tops[i]);
        }
        ll tot=0;
        ll siz = diftops.size();
        for (ll difTop : diftops) {
            ll siz2=dificDif[difTop].size();
            tot += (siz2*(siz2-1)*(siz2-2))/6LL;
            ll amt2 = diftopsms.count(difTop);
            tot += amt2*(amt2-1LL)/2LL*siz2;
        }

        siz = difdifs.size();
        for (ll difDif : difdifs) {
            ll siz2=dificTop[difDif].size();
            tot += (siz2*(siz2-1)*(siz2-2))/6LL;
            ll amt2 = difdifsms.count(difDif);
            tot += amt2*(amt2-1LL)/2LL*siz2;        
        }

        siz = min(diftops.size(),difdifs.size());
        tot += (siz*(siz-1)*(siz-2))/6LL;

        cout << tot<< endl;
    }
	exit(0);
}
