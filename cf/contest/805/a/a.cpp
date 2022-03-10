#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int l,r;
	cin >> l >> r;
	if(r-l <= 1)
		cout << r << endl;
	else
		cout << 2 << endl;
	exit(0);
}
