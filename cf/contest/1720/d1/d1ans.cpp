#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 3e5+100;

int n, vec[MAX], dp[MAX];
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> vec[i];
		dp[i] = 1;
	}
	int r = vec[0];
	for(int i = 1; i < n; i++) {
		r = max(r,vec[i]);
		for(int j = max(0,i-2*r+1); j < i; j++)
			if((vec[j]^i) < (vec[i]^j))
				dp[i] = max(dp[i],dp[j]+1);
	}
	int maxi = -INF;
	for(int i = 0; i < n; i++)
		maxi = max(maxi,dp[i]);
	cout << maxi << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
