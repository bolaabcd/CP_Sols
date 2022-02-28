#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n,k;
	cin >> n >> k;
	vector<int> v(n);
	for(int& i: v) cin >> i;
	for(int i = 0; i < k; i++) {
		int val;
		cin >> val;
		int l = 0, r = n-1;
		while(l != r) {
			int mid = (l+r)/2;
			if(v[mid] >= val)
				r = mid;
			else
				l = mid+1;
		}
		if( v[l] == val)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	exit(0);
}
