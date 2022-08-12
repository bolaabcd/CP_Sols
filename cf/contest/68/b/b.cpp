#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const MAX = 1e4;

int n;
double k;
double a[MAX];

bool cando (double eqamt) {
	int i = n-1, j = 0;
	sort(a, a+n);

	for() {
		// a[i] delivers the necessary energy, if possible
		double amtneed = (a[i] - eqamt)/k; // amt needed to pass
	}
}

int main() { _
	int kf;
	cin >> n >> kf;
	k = kf/100.0;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	double l = 0, r = 1000.0;
	for(int i = 0; i < 30; i++) {
		double mid = l+r/2.0;

		if(cando(mid))
			l = mid;
		else
			r = mid;
	}
	exit(0);
}
