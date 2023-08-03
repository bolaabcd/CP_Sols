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

// Convex Hull Trick Dinamico
//
// para double, use LINF = 1/.0, div(a, b) = a/b
// update(x) atualiza o ponto de intersecao da reta x
// overlap(x) verifica se a reta x sobrepoe a proxima
// add(a, b) adiciona reta da forma ax + b
// query(x) computa maximo de ax + b para entre as retas
//
// O(log(n)) amortizado por insercao
// O(log(n)) por query

struct Line {
	mutable ll a, b, p;
	bool operator<(const Line& o) const { return a < o.a; }
	bool operator<(ll x) const { return p < x; }
};

struct dynamic_hull : multiset<Line, less<>> {
	ll div(ll a, ll b) { 
		return a / b - ((a ^ b) < 0 and a % b);
	}
	
	void update(iterator x) {
		if (next(x) == end()) x->p = LINF;
		else if (x->a == next(x)->a) x->p = x->b >= next(x)->b ? LINF : -LINF;
		else x->p = div(next(x)->b - x->b, x->a - next(x)->a);
	}

	bool overlap(iterator x) {
		update(x);
		if (next(x) == end()) return 0;
		if (x->a == next(x)->a) return x->b >= next(x)->b;
		return x->p >= next(x)->p;
	}
		
	void add(ll a, ll b) {
		auto x = insert({a, b, 0});
		while (overlap(x)) erase(next(x)), update(x);
		if (x != begin() and !overlap(prev(x))) x = prev(x), update(x);
		while (x != begin() and overlap(prev(x))) 
			x = prev(x), erase(next(x)), update(x);
	}
	
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
#warning cuidado com overflow!
		return l.a * x + l.b;
	}
};

const int MAX = 3e3+10;
ll memo[MAX][MAX]; // k, i

int main() { __
	int n,k;
	cin >> n >> k;
	vector<ll> vals(n),pref(n+1);
	for(ll&i:vals)cin>>i;
	for(int i = 1; i <= n; i++)
		pref[i] = pref[i-1]+vals[i-1];
	
	// se n vai dividir mais, eh do i pra frente
	for(int i = 1; i <= n; i++)
		memo[1][i] = (pref[n]-pref[i-1])*(pref[n]-pref[i-1]);

	for(int k2 = 2; k2 <= k; k2++) {
		//CHT ch;
		dynamic_hull ch;
		for(int i = n+1-k2; i >= 1; i--) {
			// k2 particoes do i pra frente, comecando no i
			ch.add(-(-2*pref[i]),-(pref[i]*pref[i]+memo[k2-1][i+1]));
			memo[k2][i] = -ch.query(pref[i-1])+pref[i-1]*pref[i-1];
		}
	}

	cout << memo[k][1] << endl; // k divisoes, do 1 pra frente

	exit(0);
}
