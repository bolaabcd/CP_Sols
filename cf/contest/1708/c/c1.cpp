#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool ok(int l, vector<int> &a, int q) {
	for(int i = l+1; i < a.size(); i++)
		if(a[i] > q)
			q--;
	return q >= 0;
}

void solve() {
	int n,q;
	cin >> n >> q;
	vector<int> vec(n);
	for(int &i:vec)cin >> i;
	int l = -1, r = n-1;
	while(l != r) {
		int mid = (l+r+2)/2-1;
		if(ok(mid,vec,q))
			r = mid;
		else
			l = mid+1;
	}
	for(int i = 0; i <= l; i++)
		if(vec[i] <= q)
			cout << 1;
		else
			cout << 0;
	for(int i = l+1; i < n; i++)
		cout << 1;
	cout << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
