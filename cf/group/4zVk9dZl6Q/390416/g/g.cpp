#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int x[3],y[3];
	cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
	
	cout << 3 << endl;
	cout << x[2]+x[1]-x[0] << ' ' << y[2]+y[1]-y[0] << endl;
	cout << x[2]+x[0]-x[1] << ' ' << y[2]+y[0]-y[1] << endl;
	cout << x[0]-x[2]+x[1] << ' ' << y[0]-y[2]+y[1] << endl;

	exit(0);
}
