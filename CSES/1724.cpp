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

// Matriz

#define MODULAR false
template<typename T> struct matrix : vector<vector<T>> {
	int n, m;

	void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cout << (*this)[i][j] << " ";
			cout << endl;
		}
	}

	matrix(int n_, int m_, bool ident = false) :
			vector<vector<T>>(n_, vector<T>(m_, 0)), n(n_), m(m_) {
		if (ident) {
			assert(n == m);
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					if(i == j)
						(*this)[i][j] = 0;
					else
						(*this)[i][j] = LINF;
		}
	}
	matrix(const vector<vector<T>>& c) : vector<vector<T>>(c),
		n(c.size()), m(c[0].size()) {}
	matrix(const initializer_list<initializer_list<T>>& c) {
		vector<vector<T>> val;
		for (auto& i : c) val.push_back(i);
		*this = matrix(val);
	}

	matrix<T> operator*(matrix<T>& r) {
		assert(m == r.n);
		matrix<T> M(n, r.m);
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < r.m; j++) {
				M[i][j] = LINF;
				for (int k = 0; k < m; k++)
					M[i][j] = min(M[i][j],(*this)[i][k]+r[k][j]);
				//T add = (*this)[i][k] * r[k][j];
				//M[i][j] += add;
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
	void apply_transform(matrix M, ll e){
		auto& v = *this;
		while (e) {
			if (e&1) v = M*v;
			e >>= 1;
			M = M*M;
		}
	}
};


int main() { __
	int n,m,k;
	cin >> n >> m >> k;
	matrix<ll> mat(n,n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] = LINF;
	for(int i = 0; i < m; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		mat[a][b] = min(mat[a][b],ll(c));
	}
	mat = mat^k;
	if(mat[0][n-1] == LINF)
		cout << -1 << endl;
	else
		cout << mat[0][n-1] << endl;
	exit(0);
}
