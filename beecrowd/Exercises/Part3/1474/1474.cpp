#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e6;
typedef pair<pair<ll,ll>,pair<ll,ll>> mi; // linha, col
typedef pair<ll,ll> vec;

mi mulmod(mi fir, mi seg) {
	return {
		{((fir.f.f*seg.f.f)%MOD+(fir.f.s*seg.s.f)%MOD)%MOD, ((fir.f.f*seg.f.s)%MOD+(fir.f.s*seg.s.s)%MOD)%MOD},
		{((fir.s.f*seg.f.f)%MOD+(fir.s.s*seg.s.f)%MOD)%MOD, ((fir.s.f*seg.f.s)%MOD+(fir.s.s*seg.s.s)%MOD)%MOD}
	};
}

vec vecmulmod(mi mat, vec v) {
	return {((mat.f.f*v.f)%MOD + (mat.f.s*v.s)%MOD)%MOD, ((mat.s.f*v.f)%MOD + (mat.s.s*v.s)%MOD)%MOD};
}

int main() { _
	while(1) {
		ll n, k, l;
		cin >> n >> k >> l;
		if(cin.eof())
			break;
		vector<mi> mis(51);
		mis[0] = {{1,0},{0,1}};
		mis[1] = {{0,1},{l%MOD,k%MOD}};
		for(int i = 2; i <= 50; i++)
			mis[i] = mulmod(mis[i-1],mis[i-1]);

		mi matans = mis[0];
		n /= 5;
		for(int i = 1; n > 0; i++){
			if (n%2){
				// cout << i << endl;
				matans = mulmod(matans, mis[i]);
			}
			n /= 2;
		}
		cout.width(6);
		cout.fill('0');
		cout << vecmulmod(matans, {1,k%MOD}).first << endl;
	}

	exit(0);
}

