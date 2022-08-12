#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1000+10;

ll m,n;
ll t[MAX], z[MAX], y[MAX], bals[MAX];// b = num of baloons

bool da(ll maxtime) {
	ll totbals = 0;
	for(int i = 0; i < n; i++) {
		ll timeperpack = t[i]*z[i]+y[i];
		ll completepacks = maxtime/timeperpack;
		ll extra =min(z[i],(maxtime - completepacks*timeperpack)/t[i]);// (remainingtime)/timeperbaloon or the maximum without needing to rest
		totbals += z[i]*completepacks+extra;
		if(totbals >= m)
			return true;
	}
	return totbals >= m;
}

void get_bals(ll maxtime) {
	ll totbals = 0;
	memset(bals,0LL,n);
	for(int i = 0; i < n; i++) {
		ll need = m-totbals;
		ll timeperpack = t[i]*z[i]+y[i];
		ll completepacks = maxtime/timeperpack;
		ll extra =min(z[i],(maxtime - completepacks*timeperpack)/t[i]);// (remainingtime)/timeperbaloon or the maximum without needing to rest
		bals[i] = min(need,z[i]*completepacks+extra);
		totbals += bals[i];
		if(totbals >= m)
			return;
	}
}

int main() { _
	cin >> m >> n;
	for(int i = 0; i < n; i++)
		cin >> t[i] >> z[i] >> y[i];

	int l = 0, r = 1e9;
	while(l != r) {
		ll mid = (l+r)/2;
		if(da(mid))
			r = mid;
		else
			l = mid+1;
	}
	get_bals(l);
	cout << l << endl;
	for(int i = 0; i < n; i++)
		cout << bals[i] << " ";
	cout << endl;

	exit(0);
}
