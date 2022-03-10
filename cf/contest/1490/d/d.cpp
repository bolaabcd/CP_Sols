#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 110;

int n;
int res[MAX];
int vec[MAX];

void calc(int l, int r, int alt) {
	if(l < 0 || r >= n || r < 0 || l >= n || r < l)
			return;
	int maxi = -INF, mp = -1;
	for(int i = l; i <= r; i++){
		if(vec[i] > maxi){
			maxi = vec[i];
			mp = i;
		}
	}
	res[mp] = alt;
	calc(l,mp-1,alt+1);
	calc(mp+1,r,alt+1);
}

void solve() {
	cin >> n;
	memset(res,-1,n);
	for(int i = 0; i < n; i++)
		cin >> vec[i];
	calc(0, n-1, 0);
	for(int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	exit(0);
}
