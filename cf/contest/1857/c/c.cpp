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

void solve() {
	int n;
	cin >> n;
	map<int,int> mp;
	for(int i = 0; i < (n*(n-1))/2; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}
	vector<int> ans;
	int k = n-1;
	for(auto [a,b]:mp) {
		int k2 = k;
		int rep = 0;
		while(b) {
			for(int i = 0; i < k2; i++)
				b--;
			ans.pb(a);
			k2--;
			rep++;
		}
		k-=rep;
	}
	for(int i: ans)
		cout << i << ' ';
	cout << ans.back() << endl;
}

int main() { __
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}

