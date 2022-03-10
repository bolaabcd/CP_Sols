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
	int n,s;
	cin >> n >> s;
	vector<int> pes(n);
	vector<int> pre(n);
	for(int& i:pes) cin >> i;
	for(int& i:pre) cin >> i;

	int j = 0;
	ll valatual = 0;
	ll pesatual = 0;
	ll maior = pesatual;
	for(int i = 0; i < n; i++) {
		for(;j < n && pesatual + pes[j] <= s; j++) pesatual += pes[j], valatual += pre[j];
		maior = max(maior,valatual);
		debug(i,j,valatual,pesatual);
		pesatual -= pes[i];
		valatual -= pre[i];
		
	}
	

	cout << maior << endl;

	exit(0);
}
