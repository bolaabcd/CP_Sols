#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 2e5+10;

ll n,x;
ll sums[MAX];

ll rec(int l, int r) {
	if(l == r)
		return 0;
	int l2 = l, r2 = r;

	ll tot = sums[r]-sums[l-1];
	
	while(l2 != r2) {
		int mid = (l2+r2+1)/2;
		if(sums[mid]-sums[l-1] <= tot/2)
			l2 = mid;
		else
			r2 = mid-1;
	}
	
	ll maxi = max(sums[l2]-sums[l-1],sums[r]-sums[l2]);

	int l2o = l2;
	for(int i = 1; i <= 1000; i++) {
		if(l2o+i <= r and max(sums[l2o+i]-sums[l-1],sums[r]-sums[l2o+i]) < maxi) {
			maxi = max(sums[l2o+i]-sums[l-i],sums[r]-sums[l2o+i]);
			l2=l2o+i; 
		}
		if(l2o-i >= l and max(sums[l2o-i]-sums[l-1],sums[r]-sums[l2o-i]) < maxi) {
			maxi = max(sums[l2o-i]-sums[l-i],sums[r]-sums[l2o-i]);
			l2=l2o-i; 
		}
	}

	return tot + rec(l,l2) + rec(l2+1,r);
}

int main() { _
	cin >> x >> n;
	for(int i = 0; i < n; i++)
		cin >> sums[i];
	sort(sums,sums+n+1);
	for(int i = 1; i <= n; i++)
		sums[i] += sums[i-1];
	
	cout << rec(1,n) << endl;
	exit(0);
}
