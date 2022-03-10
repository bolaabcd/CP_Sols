#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int q;
	cin >> q;
	while(q--) {
		ll n, ninit;
		cin >> n;
		ninit = n;
		vector<ll> b3;

		while(n != 0LL) {
			b3.push_back(n%3LL);
			n-=n%3LL;
			n/=3LL;
		}

		bool bad = false, tem0 = false;
		int last0 = -1;
		for(int i = b3.size()-1; i >=0 ; i--){
			if(b3[i] == 2)
				bad = true;
			if(!bad && b3[i] == 0)
				last0 = i;
			if(b3[i] == 0)
				tem0 = true;
		}

		if(!bad) {
			cout << ninit << endl;
			continue;
		}
		if(!tem0 || last0 == -1){
			cout <<  pow(3,b3.size()) << endl;
			continue;
		}


		// reverse(b3.begin(), b3.end());
		ll ans = 0;
		ll m3 = pow(3,b3.size()-1);
		for(int i = b3.size()-1; i > last0; i--){
			assert(b3[i] != 2);
			ans += m3*b3[i];
			m3 /= 3;
		}
		ans += m3;
		// m3*=3;


		cout << ans << endl;

	}
	exit(0);
}
