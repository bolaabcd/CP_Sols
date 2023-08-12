#include <bits/stdc++.h>
#define M_PI 3.14159265358979323846


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
	ll n,R,r;
	cin >> n >> R >> r;
	ll max = 0, k = 2;
	while(2*R - k*r >= 0) {
		ll le= 1, ri = 110;
		while(le != ri) {
			ll mid = (le+ri+1)/2;
			if((2*R-k*r)/2ll*(2*R-k*r)/2ll*2*(1-cos((2ll*M_PI)/mid)) >= 4*r*r)
				le = mid;
			else
				ri = mid-1;
		}
		max += le;
		k += 4;
	}
	if(max >= n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	exit(0);
}
