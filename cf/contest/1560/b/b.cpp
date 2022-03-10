#include <bits/stdc++.h>

using namespace std;

#define _                         \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int oia(int a, int n) {
	assert(n%2==0);
	if (a <= n/2)
		return a  + n/2;
	else
		return a - n/2;
}

int ene(int a, int b) {
	if (a > b)
		swap(a,b);
	return (2*b - 2*a);
}

int main()
{
	_ int t;
	cin >> t;
	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int n = ene(a,b);
		if(oia(a, n) != b || oia(b, n) != a || c > n || a > n || b > n)
			cout << -1 << endl;
		else
			cout << oia(c, n) << endl;
	}
	exit(0);
}
