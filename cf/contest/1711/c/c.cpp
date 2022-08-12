#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool deu(int n, int m, int k, vector<int>& amts) { // fileiras de tamanho m, precisamos de n delas
	ll tot = 0;
	bool axo = false;
	for(int i = 0; i < k; i++) {
		ll soma = amts[i]/m;
		if (soma >= 2)
			tot+= soma;
		if (soma >= 3) {
			axo = true;
		}
	}
	//cout << tot << endl;
	if (tot < n)
		return false;
	else if (tot == n)
		return true;
	if (k == 1)
		return true;

	if(n%2) {
		if (!(tot - n)%2)
			return true;
		else if (axo)
			return true;
		else
			return false;
	}
	else return true;
}

void solve() {
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> amts(k);
	for(int&i:amts)cin>>i;
	if(deu(n,m,k,amts)) cout << "Yes" << endl;
	else if (deu(m,n,k,amts)) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
