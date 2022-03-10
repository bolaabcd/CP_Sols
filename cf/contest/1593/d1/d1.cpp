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

int gcd(int a,int b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}

int main() { _
	int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for(int& v: vec) cin >> v;
        int ans = abs(vec[1]-vec[0]);
        for(int i = 0; i < n; i++ ){
            for (int j = i+1; j < n; j ++) {
                ans = gcd(ans,abs(vec[i]-vec[j]));
            }
        }
        if (ans == 0)
            ans = -1;
        cout << ans << endl;
    }
	exit(0);
}
