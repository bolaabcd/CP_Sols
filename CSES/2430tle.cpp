#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void printa(int t, int siz) {
	for(int k = (1<<(siz-1)); k >= 1; k /= 2)
		if(t&k)
			cout << 1;
		else
			cout << 0;
	cout << endl;
}

int gettot(int mask, int siz) {
	int tot = 0, v0 = 1, v1 = 1, nzs = 0, nuns = 0;
	for(int k = 1; k < (1<<siz); k*=2) {
		if(mask&k) {
			tot += v1;
			tot += nzs*v1;
			v1 = v1 + nzs*v0;
			nuns++;
			nzs = 0;
		} else {
			tot += v0;
			tot += nuns*v1;
			v0 = v0+nuns*v1;
			nzs++;
			nuns = 0;
		}
	}
	return tot;
}

int main() { __
	int n;
	cin >> n;
	int msiz = -1;
	for(int siz = 1; siz <= 30; siz++) {
		for(int s = 0; s < 4e7+10 and s < (1<<siz); s++) {
			int tot = gettot(s,siz);
			msiz = max(msiz,tot);
			if(tot == n) {
				cout << siz << endl;
				printa(s,siz);
				exit(0);
			}
		}
	}

	cout << msiz << endl;

	exit(0);
}
