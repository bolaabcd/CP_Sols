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
		int n,m;
		cin >> n >> m;
		n--;
		m--;
		cout << n+m+min(n,m)+(n != 0 or m != 0) << endl;
	}
	exit(0);
}
