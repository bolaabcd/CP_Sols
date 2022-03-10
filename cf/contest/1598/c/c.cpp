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
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> vec(n);
        multiset<ll> ms;
        set<ll> ss;
        ll soma = 0;
        for(ll& v : vec) cin >> v, soma += v, ms.insert(v), ss.insert(v);
        
        if (n == 2 && soma != 0) {
            cout << 0 << endl;
            continue;
        }

        if ((2*soma)%n) {
            cout << 0 << endl;
            continue;
        }

        ll dMedia = (2*soma)/n;
        ll total = 0;
        for (ll val : ss) {
            ll amtVal =  ms.count(val);
            if (val > dMedia/2)
                continue;
            if (val == dMedia/2 && (dMedia %2 == 0)){
                total +=amtVal*(amtVal-1)/2;
                continue;
            }
            
            ll otro = (2*soma)/n - val;
            ll amtOtro = ms.count(otro);
            total += amtVal * amtOtro;
        }
        cout << total << endl;
    }
	exit(0);
}
