#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 2e5+100;

int n;
int a[MAX];

bool fine(int prefsiz) {
	int i = prefsiz,j = n-1;
	int last = -INF;
	while(i < j) {
		assert(i >= 0);
		assert(i < n);
		assert(j >= 0);
		assert(j < n);
		if(a[i] > a[j]){
			if(a[j] < last)
				return false; // non-decreasing
			else
				last = a[j--];
		} else {
			if(a[i] < last)
				return false; // non-decreasing
			else
				last = a[i++];
		}
	}
	return true;
}

void solve() {
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int l = 0,r = n;
	while(l != r) {
		int mid = (l+r)/2;
		if(fine(mid))
			r = mid;
		else
			l = mid+1;
	}
	cout << l << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	exit(0);
}
