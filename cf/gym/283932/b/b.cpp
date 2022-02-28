#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e7+10;

int n, k;
int vs [MAX];
bool checa(double m) {
	int amt = 0;
	for(int i = 0; i < n; i++) {
		amt += floor(vs[i]/m);
		if(amt >= k)
			break;
	}
	return amt >= k;
}


int main() { _
	cin >> n >> k;
	double l = 0, r = MAX;

	for(int i = 0; i < n; i++)
		cin >> vs[i];

	for(int i = 0; i < 500; i++) {
		double m = (l+r)/2;
		if(checa(m))
			l = m;
		else
			r = m;
	}
	cout << fixed << setprecision(9);
	cout << l << endl;

	exit(0);
}
