#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const short SINF = 0x3f3f;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

short a[3000];

void solve() {
	short n,k, minans = SINF, maxval = -SINF;
	cin >> n >> k;
	for(short i = 0; i < n; i++) {
		cin >> a[i];
		maxval = max(maxval,a[i]);
	}
	for(short i = maxval; i > 0; i--) {
		short maxi = -SINF, mini = SINF;
		bool imposs = false;
		for(short j = 0; j < n; j++) {
			short l = 1, r = k;
			while(l<r) {
				short mid = (l+r)/2;
				if(a[j]/mid <= i)
					r = mid;
				else
					l = mid+1;
			}
			if(l != r or a[j]/r > i) {
				imposs = true;
				break;
			}
			l = a[j]/l;
			maxi = max(maxi, l);
			mini = min(mini, l);
		}
		if(imposs)
			break;
		minans = min(minans, short(maxi-mini));
	}
	assert(minans != SINF);
	cout << minans << endl;
}

int main() { _
	short t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
