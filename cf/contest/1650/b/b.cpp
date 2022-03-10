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
		int l,r,a;
		cin >> l >> r >> a;
		int v1 = r/a + r%a, v2 = a+r/a-2;
		if((r/a)*a -1 >=l)
			cout << max(v1,v2) << endl;
		else
			cout << v1 << endl;
	}
	exit(0);
}
