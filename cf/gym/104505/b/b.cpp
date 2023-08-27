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
const ll LINF = 0x3f3f3f3f3f3f3f3f;


int main() { __
	ll n;
	cin >> n;
	vector<ll> vec(n);
	ll nimp = 0, limp;
	for(ll i = 0; i < n; i++) {
		cin >> vec[i];
		nimp+=vec[i]%2;
		if(vec[i]%2)
			limp = i;
	}
	ll a,b;
	cin >> a >> b;
	a = min(a,b);
	if(nimp%2) {
		cout << -1 << endl;
		exit(0);
	}
	vector<ll> vals;
	for(ll i = 0; i < n; i++) {
		if(vec[i]%2) {
			if(limp > i) {
				vals.pb(a*(n-limp+i));
			} else {
				vals.pb(a*(i-limp));
			}
			limp = i;
		}
	}
	//assert(vals.size()%2 == 0);
	ll op1 = 0, op2 = 0;
	for(int i = 0; i < vals.size(); i+= 2)
		op1 += vals[i];
	for(int i = 1; i < vals.size(); i+= 2)
		op2 += vals[i];
	cout << min(op1,op2) << endl;

	exit(0);
}
