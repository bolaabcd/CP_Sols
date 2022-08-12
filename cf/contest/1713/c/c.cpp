#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<ll> sqrs;

vector<ll> ans;

void rec(ll n) {
	if(n < 0) {
		ans.clear();
		ans.push_back(-1);
		return;
	} else if (n == 1) {
		ans.push_back(0);
		return;
	} else if (n == 2) {
		ans.push_back(1);
		ans.push_back(0);
		return;
	}
	//cout << *lower_bound(sqrs.begin(),sqrs.end(),1) << endl;
	ll fg = *lower_bound(sqrs.begin(),sqrs.end(),n-1);
	//cout << fg << endl;
	if(fg == n-1) {
		for(ll i = n-1; i >= 0; i--)
		ans.push_back(i);
	} else {
		ll fg2 = *lower_bound(sqrs.begin(),sqrs.end(),n);
		rec(fg2-n+1);
		for(ll i = n-1; i > fg2-n; i--)
			ans.push_back(i);
	}
}

int main() { _
	sqrs.resize(112345);
	for(ll i = 0; i < sqrs.size(); i++)
		sqrs[i] = i*i;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		//if(n > 1000) {
		//	cout << -1 << endl;
		//	continue;
		//}
		ans.clear();
		rec(n);
		for(ll i : ans) {
			cout << i << ' ';
		}
		cout << endl;
	}
	exit(0);
}
