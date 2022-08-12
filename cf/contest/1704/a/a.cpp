#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool has(string &s, char c, int siz) {
	for(int i = 0; i < siz; i++)
		if(s[i] == c)
			return true;
	return false;
}

void solve() {
	int n, m;
	cin >> n >> m;
	string a,b;
	cin >> a >> b;
	for(int i = 0; i < m-1; i++) {
		if(a[n-i-1] != b[m-i-1]) {
			cout << "No" << endl;
			return;
		}
	}
	if(a[n-m] == b[m-m])
		cout << "Yes" << endl;
	else if(has(a,b[m-m],n-m))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
