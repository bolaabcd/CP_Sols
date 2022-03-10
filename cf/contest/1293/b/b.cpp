#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	long double tot = 0;
	int nbr,n;
	cin >> nbr;
	n = nbr;
	for(int i = 0; i < nbr; i ++) {
		tot += ld(1)/ld(n);
		n-=1;
	}
	cout << setprecision(900);
	cout << tot << endl;
	exit(0);
}
