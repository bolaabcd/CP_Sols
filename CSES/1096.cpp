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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll MOD = 1e9+7;

template<typename T> struct matrix : vector<vector<T>> {
	int n, m;

	matrix(const vector<vector<T>>& c) : vector<vector<T>>(c),
		n(c.size()), m(c[0].size()) {}

	matrix(int n_, int m_, bool ident = false) :
			vector<vector<T>>(n_, vector<T>(m_, 0)), n(n_), m(m_) {
		if (ident) {
			assert(n == m);
			for (int i = 0; i < n; i++) (*this)[i][i] = 1;
		}
	}

	matrix<T> operator*(matrix<T>& r) {
		assert(m == r.n);
		matrix<T> M(n, r.m);
		for (int i = 0; i < n; i++) for (int k = 0; k < m; k++)
			for (int j = 0; j < r.m; j++) {
				T add = (*this)[i][k] * r[k][j];
				M[i][j] += add%MOD;
				if (M[i][j] >= MOD) M[i][j] -= MOD;
			}
		return M;
	}
	matrix<T> operator^(ll e){
		matrix<T> M(n, n, true), at = *this;
		while (e) {
			if (e&1) M = M*at;
			e >>= 1;
			at = at*at;
		}
		return M;
	}
};


int main() { __
	ll n;
	cin >> n;
	switch(n) {
		case 1:
		cout << 1 << endl;
		break;
		case 2:
		cout << 2 << endl;
		break;
		case 3:
		cout << 4 << endl;
		break;
		case 4:
		cout << 8 << endl;
		break;
		case 5:
		cout << 16 << endl;
		break;
		case 6:
		cout << 32 << endl;
		break;
		default:
		vector<vector<ll>> v = {
			{1,1,1,1,1,1},
			{1,0,0,0,0,0},
			{0,1,0,0,0,0},
			{0,0,1,0,0,0},
			{0,0,0,1,0,0},
			{0,0,0,0,1,0},
		};
		vector<vector<ll>> v2 = {{32},{16},{8},{4},{2},{1}};
		matrix m(v),m2(v2);
		cout << ((m^(n-6))*m2)[0][0] << endl;
	}
	exit(0);
}
