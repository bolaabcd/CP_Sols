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

int main() { __
	ll n,m;
	cin >> n >> m;
	// de n pra m
	if(m <= n) {
		cout << n-m << endl;
		exit(0);
	}
	ll p = 1, ans = 0;
	while(n < m){
		n *= 2ll;
		ans++;
		p *= 2ll;
	}
	while(p > 1ll and n > m) {
		if(n-(p*((n-m)/p)) >= m) {
			ans += ((n-m)/p);
			n-=p*((n-m)/p);
		}
		p /= 2ll;
	}
	
	cout << ans + n-m << endl;
	exit(0);
}
