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

int n,k;
bool dah(ll v, vector<ll> &vec) {
	int amt = 1;
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		if(vec[i] > v)
			return false;
		if(sum + vec[i] > v) {
			sum = 0;
			amt++;
		}
		sum += vec[i];
	}
	return amt <= k;
}

int main() { __
	cin >> n >> k;
	vector<ll> vec(n);
	for(ll&i:vec)
		cin >> i;
	ll l = 0, r = 1e16;
	while(l != r) {
		ll mid = (l+r)/2;
		if(dah(mid,vec))
			r = mid;
		else
			l = mid+1;
	}
	cout << l << endl;
	exit(0);
}
