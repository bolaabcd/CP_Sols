#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n, k;
	cin >> n;
	vector<int> a(n);
	for(int& i: a) cin >> i;
	sort(a.begin(), a.end());
	cin >> k;
	for(int i = 0; i < k; i++) {
		int x,y;
		cin >> x >> y;
		if(x > a[n-1] || y < a[0]){
			cout << 0 << endl;
			continue;
		}
		int l = 0, r = n-1;
		int umeqy, pmaqx;
		while(l != r) {
			int m = (l+r+1)/2;
			if(a[m] <= y)
				l = m;
			else
				r = m-1;
		}
		umeqy = l;
		l = 0, r = n-1;
		while(l != r) {
			int m = (l+r)/2;
			if(a[m] >= x)
				r = m;
			else
				l = m+1;
		}
		pmaqx = r;
		cout << umeqy - pmaqx + 1 << " ";
	}
	cout << endl;
	exit(0);
}
