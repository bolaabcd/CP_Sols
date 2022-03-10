#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
ll x0,y000,ax,ay,bx,by;
vector<pair<ll,ll>> nozes;

ll f (ll z, ll a, ll b) {
	return z*a+b;
}

ll finv (ll z, ll a, ll b) {
	assert((z-b)%a==0);
	return (z-b)/a;
}

ll tmp_ate(ll xi, ll yi, ll xf, ll yf) {
	return abs(xi-xf) + abs(yi-yf);
}
//abc
// 32 e 16
ll tras(ll nox, ll noy, ll tempo) {
	ll soma = 0;
	while(1) {
		if(tempo < 0) {
			return soma;
		}
		if (nox == x0) {
			assert(noy == y000);
			return soma+1;
		}
		// cout << "AAA" << endl;
		soma += 1;
		ll noxold = nox, noyold = noy;
		nox = finv(nox,ax,bx);
		noy = finv(noy,ay,by);
		tempo -= tmp_ate(noxold,noyold,nox,noy);
	}
}

ll frente(ll nox, ll noy, ll tempo) {
	ll soma = 0;
	while(1) {
		if(tempo < 0) {
			return soma;
		}
		if (nox == nozes[nozes.size()-1].first) {
			assert(noy = nozes[nozes.size()-1].second);
			return soma+1;
		}
		// cout << "BBBB" << endl;
		soma += 1;
		ll noxold = nox, noyold = noy;
		nox = f(nox,ax,bx);
		noy = f(noy,ay,by);
		tempo -= tmp_ate(noxold,noyold,nox,noy);
	}
}
//1 1 2 2 0 0 31 31 2
//1
//1 1 2 2 0 0 31 31 2
//0
//1 1 2 2 0 0 31 31 34
//2
//1 1 2 2 0 0 31 31 33
//1
//1 1 2 2 0 0 3 3 14
//3
//1 1 2 2 0 0 4 4 6
//3
//1 1 2 2 0 0 4 4 12
//3
//3 3 2 2 0 0 2 2 2
//1
//1 1 100 100 0 0 9999999999999999 9999999999999999 2
//1
//100 200 2 2 0 0 12 13 400
//1
//1 1 2 2 1 1 1 1 4
//1
//1 1 10 10 0 0 5000000000000000 5000000000000000 10000000000000000
//16



//10000000000000000
int main() { _
	cin >> x0 >> y000 >> ax >> ay >> bx >> by;

	ll xs,ys,t;
	cin >> xs >> ys >> t;

	for (ll x = x0, y =y000; x <= 3e16+20 && y <= 3e16+20 ; x = f(x,ax,bx), y = f(y,ay,by)) {
		nozes.emplace_back(x,y);
	}
//  xooooooooooxooooooooooxoooooooooxoo
	ll melhor = 0;
	for (pair<ll,ll> no : nozes) {
		ll tmp = t - tmp_ate(xs,ys,no.first,no.second);
		if ( tmp >= 0 ) {
			melhor = max(melhor,frente(no.first,no.second,tmp));

			if (no != nozes[nozes.size()-1]) {
				ll ida = tmp_ate(no.first,no.second,f(no.first,ax,bx),f(no.second,ay,by));
				if(tmp-2*ida >= 0)
					melhor = max(melhor, 1 + tras(no.first,no.second,tmp-2*ida));
			}

			ll volta = tmp_ate(no.first,no.second,x0,y000);
			if( tmp-2*volta >= 0) {
				melhor = max(melhor,tras(no.first,no.second,tmp) + frente(no.first,no.second,tmp-2*volta)-1);
			} else {
				melhor = max(melhor,tras(no.first,no.second,tmp));
			}
		}
	}

	cout << melhor << endl;
	

	exit(0);
}
