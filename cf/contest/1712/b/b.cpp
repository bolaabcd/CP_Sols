#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve () {
	int n;
	cin >> n;
	if(n%2)
		cout << 1 << ' ';
	for(int i = n%2; i < n; i+=2) {
		cout << i+2 << ' ' << i+1 << ' ';
	}
	cout << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
