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
		int n,m;
        cin >> n >> m;
        set<int> proib;
        for (int i = 0; i < m; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            proib.insert(b);
        }
        int meio;
        for (int i = 1; i <= n; i++) {
            if (!proib.count(i)) {
                meio = i;
                break;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i != meio) {
                cout << i <<" "<< meio << endl;
            }
        }
	}
	exit(0);
}
