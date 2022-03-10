#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll testa (int c, set<int> &amts, multiset<int> &amtsms) {
	ll soma = 0;
	for(int i : amts) {
		int val = amtsms.count(i);

		if(i < c)
			soma += i*val;
		else if(i > c)
			soma += (i-c)*val;
	}
	return soma;
}

void solve() {
	int n;
	cin >> n;
	multiset<int> a;
	set<int> as;
	for(int i = 0; i < n; i++) {
		int v;
		cin >> v;
		a.insert(v);
		as.insert(v);
	}
	set<int> amts;
	multiset<int> amtsms;
	for(int i: as){
		amtsms.insert(a.count(i));
		amts.insert(a.count(i));
	}

	ll rem = INF;
	for(int i: amts)
		rem = min(testa(i, amts, amtsms),rem);

	cout << rem << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	exit(0);
}
