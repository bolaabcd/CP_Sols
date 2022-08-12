#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	ll n;
	cin >> n;
	assert(n <= 1e12 && n >= 1);
	vector<bool> prim((int)1e6+1, true);
	prim[1] = false;
	for(int i = 2; i <= 1e6; i++) {
		if(prim[i])
			for(int j = i+i; j <= 1e6; j += i) {
				prim[j] = false;
			}
	}

	ll amtdiv = 0;
	for(ll i = 2; i <= 1e6; i++) {
		if(prim[(int)i] && (n%i) == 0L) {
			while(n%i == 0L){
				n/= i;
			}
			amtdiv++;
		}
	}
	// has at most one prime factor greater than 1e6, and if n has it, then we will not find all factors in our loop that goes up to 1e6
	if(n > 1)
		amtdiv++;

	amtdiv = pow(2,amtdiv)-amtdiv-1;
	assert(amtdiv >= 0);
	cout << amtdiv << endl;
	exit(0);
}
