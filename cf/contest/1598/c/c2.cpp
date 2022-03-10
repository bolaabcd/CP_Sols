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
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> vec(n);
        multiset<ll> ms;
        ll soma = 0;
        for(ll& v : vec) cin >> v, soma += v, ms.insert(v);
        // debug(n,soma);
        if (!soma%2 && soma%n || (n == 2  && soma !=0)) {
            cout << 0 << endl;
            continue;
        }
        ll Dmedia = (2*soma) / n;
        sort(vec.begin(),vec.end());
        ll total = 0;
        set<ll> foi;
        for (ll m: ms) {
            if (foi.count(m))
                continue;
            int amtm = ms.count(m);
            int amtotro = ms.count(Dmedia - m);
            if (m == Dmedia/2 && soma%2 == 0)
                total += amtm*(amtm-1)/2;
            else
                total += amtm * amtotro;
            foi.insert(m); 
            foi.insert(Dmedia - m);
        }
        cout << total << endl;
    }
	exit(0);
}

