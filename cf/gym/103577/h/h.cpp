#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

long double d,v0,v1,v2,t, epsi = 1.0/(1024.0*1024.0*1024.0);

long double rec(long double e,long double r,long double T,long double t1) {
	if(abs(T-e) < epsi) {
		long double t2 = (r-T-t1*(v1-v2))/(v2-v1);
		assert(t2>t1);
		
		long double ne = e+(t2-t1)*v0;
		long double nr = r+(t2-t1)*v1;
		long double nT = T+(t2-t1)*v2;
		nr = min(nr,d);

		assert(ne >= e);
		assert(nr >= r);
		assert(nT >= T);

		if(t2 > t)
			return T+(t-t1)*v2;
		return rec(ne,nr,nT,t2);
	} else {
		assert(abs(T-r) < epsi);
		long double t2 = (e-T-t1*(v0+v2))/(-v2-v0);
		assert(t2>t1);

		long double ne = e+(t2-t1)*v0;
		long double nr = r+(t2-t1)*v1;
		long double nT = T-(t2-t1)*v2;
		nr = min(nr,d);

		assert(ne >= e);
		assert(nr >= r);
		assert(nT <= T);

		if(t2 > t)
			return T-(t-t1)*v2;
		return rec(ne,nr,nT,t2);
	}
}

int main() { _
	cin >> d >> v0 >> v1 >> v2 >> t;
	cout << fixed << setprecision(9);
	if(t*v0 >= d)
		cout << d << endl;
	else
		cout << rec(0,1,0,0) << endl;
	exit(0);
}
