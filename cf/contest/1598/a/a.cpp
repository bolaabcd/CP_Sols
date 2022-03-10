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
		int n;
		cin >> n;
		vector<char> f(n);
		vector<char> s(n);
		bool nao = false;
		for(char& fi: f) cin >> fi;
		for(int i =0; i < n; i++) {
			cin >> s[i];
			if ((s[i]=='1') && (f[i]=='1'))
				nao = true;
		}
		if (nao)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	exit(0);
}
