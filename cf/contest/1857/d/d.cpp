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
	vector<int> a(n),b(n);
	vector<pii> c(n);
	for(int&i:a)cin>>i;
	for(int&i:b)cin>>i;
	for(int i = 0; i < n; i++)
		c[i] = {-(a[i]-b[i]),i};
	sort(c.begin(),c.end());
	vector<int> ans;
	int j = 0;
	while(j < n and c[j].f == c[0].f) {
		ans.pb(c[j].s);
		j++;
	}
	sort(ans.begin(),ans.end());
	cout << ans.size() << endl;
	for(int i: ans)
		cout << i+1 << ' ';
	cout << endl;
}

int main() { __
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}

