#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int t;
void solve() {
	string s;
	cin >> s;
	assert(s[0] == 'P');
	cout << s << endl;
	string name = "XY";
	while(name[0] != 'T' || name[1] != 'P') {
		cin >> name;
		cout << name << endl;
	}

}

int main() { _
	cin >> t;
	while(t--) {
		solve();
	}
	exit(0);
}
