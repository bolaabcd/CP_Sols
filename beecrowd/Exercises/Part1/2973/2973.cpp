#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5;

int n,c,t;
int ps[MAX];

bool possible(int time) {
	// copy of c
	int cpc = c;
	int remtime = time, rempops = 0;
	for(int i = 0; i < n; i++) {
		int if_i_stop_here = remtime - (ps[i] + rempops)/t - (((ps[i]+rempops) % t) > 0);
		if( if_i_stop_here >= 0){
			remtime = remtime - (ps[i] + rempops)/t;
			rempops = (ps[i] + rempops) % t;
		} else {
			remtime = time;
			rempops = 0;
			cpc--;
			if( cpc <= 0)
				return false;
			i--;
		}
	}
	return true;
}

int main() { _
	cin >> n >> c >> t;


	for(int i = 0; i < n; i++)
		cin >> ps[i];

	// binary search to find the smallest time
	int l = 0, r = 1e9;
	while(l != r) {
		int mid = (l+r)/2;
		if(possible(mid))
			r = mid;
		else
			l = mid+1;
	}

	cout << l << endl;

	exit(0);
}
