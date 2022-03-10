#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int t;
	cin >> t;
	while(t--) {
		ll a,b;
		cin >> a >> b;
		ll men = min(a,b);
		ll mai = max(a,b);
		if (mai > 3*men) {
			cout << men << endl;
		} else {
			cout << (mai+men)/4 << endl;
		}
	}
	exit(0);
}
