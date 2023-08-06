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
	int n,x;
	cin >> n >> x;
	vector<int> vec(n);
	for(int&i:vec)cin>>i;
	ll sum = 0;
	int l = 0, r = 0, ans = 0;
	while(l < n) {
		while(r < n and sum < x) {
			sum += vec[r];
			r++;
		}
		ans+=sum==x;
		sum -= vec[l];
		l++;
	}
	cout << ans << endl;
	exit(0);
}
