#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5+100;

// lazy propagation, worst is the biggest difference plus one.
int mini[4*MAX+100], maxi[4*MAX+100], worst[4*MAX+100];
int n, k, t;

void prop(int p) {
	if (worst[p] == -1)
		return;
	else if (worst[2*p] == -1 and worst[2*p+1] == -1) {
		worst[2*p] = worst[2*p+1] = worst[p];
		mini[2*p] = mini[2*p+1] = mini[p];
		maxi[2*p] = maxi[2*p+1] = maxi[p];
	} else if (worst[2*p+1] == -1) {
		worst[2*p+1] = worst[p];
		mini[2*p+1] = mini[p];
		maxi[2*p+1] = maxi[p];

		assert(mini[p] > maxi[2*p]);
		worst[2*p] = max(max(worst[p],worst[2*p]), mini[p]-maxi[2*p]);
		maxi[2*p] = maxi[p];
	} else if (worst[2*p] == -1) {
		worst[2*p] = worst[p];
		mini[2*p] = mini[p];
		maxi[2*p] = maxi[p];

		assert(mini[p] > maxi[2*p+1]);
		worst[2*p+1] = max(max(worst[p],worst[2*p+1]), mini[p]-maxi[2*p+1]);
		maxi[2*p+1] = maxi[p];
	} else {
		assert(mini[p] > maxi[2*p]);
		worst[2*p] = max(max(worst[p],worst[2*p]), mini[p]-maxi[2*p]);
		assert(mini[p] > maxi[2*p+1]);
		worst[2*p+1] = max(max(worst[p],worst[2*p+1]), mini[p]-maxi[2*p+1]);
		maxi[2*p] = maxi[2*p+1] = maxi[p];
	}
	worst[p] = -1;
	maxi[p] = mini[p] = 0;
}

void water(int p, int in, int fin, int l, int r, int day) {
	//cout << in << ' '<< fin << ' ' << mini[p] << ' ' << maxi[p] << endl;
	if (in > r or fin < l)
		return;
	if (l <= in and fin <= r) {
		if (worst[p] == -1) {
			maxi[p] = day;
			mini[p] = day;
			worst[p] = 0;
		} else {
			assert(day-maxi[p] > 0);
			worst[p] = max(worst[p], day-maxi[p]);//maxi=0 by default, worst = -1
			maxi[p] = day;
		}
		return;
	}
	prop(p);
	int mid = (in+fin)/2;
	water(2*p,in,mid,l,r,day);
	water(2*p+1,mid+1,fin,l,r,day);
}

bool alive(int p, int in, int fin, int which) {
	if (in > which or fin < which)
		return false;
	if (in == fin) {
		 // cout << in << ' ' << fin << ' ' << worst[p] << endl;
		 // cout << (worst[p] <= t) << endl;
		return worst[p] <= t;
	}
	prop(p);
	// cout << in << ' ' << fin << ' ' << worst[p] << endl;
	int mid = (in+fin)/2;
	// int q1 = alive(2*p, in ,mid, which), q2 = alive(2*p+1,mid+1,fin,which);
	//if (which == 8)
	//	cout << which << ' ' << q1 << ' ' << q2 << endl;
	return alive(2*p,in,mid,which) or alive(2*p+1,mid+1,fin,which);
}

void nullify(int p, int in, int fin) {
	maxi[p] = mini[p] = 0;
	worst[p] = -1;
	if (in == fin)
		return;

	int mid = (in+fin)/2;
	nullify(2*p,in,mid);
	nullify(2*p+1,mid+1,fin);
}

void solve() {
	nullify(1,0,n-1);
	water(1,0,n-1,0,n-1,0);
	for(int i = 0; i < k; i++) {
		int l, r;
		cin >> l >> r;
		water(1,0,n-1,l-1,r-1,i+1);
	}
	water(1,0,n-1,0,n-1,k+1);
	vector<int> ans;
	for(int i = 0; i < n; i++)
		if(alive(1,0,n-1,i))
			ans.pb(i+1);
	if (ans.size() == 0) {
		cout << 0 << endl;
		return;
	}
	cout << ans.size() << ' ';
	for (int i = 0; i < int(ans.size())-1; i++)
		cout << ans[i] << ' ';
	cout << ans.back() << endl;
}

int main() { _
	while(1) {
		cin >> n >> k >> t;
		if(cin.eof())
			break;
		// cout << "SOL: " << endl;
		solve();
	}
	exit(0);
}

