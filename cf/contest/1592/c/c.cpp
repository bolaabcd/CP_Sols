#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> arv;
vector<int> vals;

vector<bool> visits; 
int maxAmt;
void dfs_eq(int init, int valat, int amt) {
	if (visits[init])
		return;
	visits[init] = true;
	maxAmt = max(maxAmt,amt);
	//cout << maxAmt << "XXX" << endl;
	for (int adj : arv[init]) {
		if (valat == vals[adj]){
			dfs_eq(adj,vals[adj], amt + 1);
		} else if (vals[adj] == 0) {
			dfs_eq(adj,vals[adj], amt);
		}
	}
}

vector<int> arv2;
int dfs_arv(int init, int raiz) {
	if (visits[init])
		return 0;
	visits[init] = true;
	for (int &adj : arv[init]) {
		arv2[init] ^= dfs_arv(adj,raiz);
	}
	return arv2[init];

}

int main() { _
	int t;
	cin >> t;
	while (t--) {
		int n,k;
		cin >> n >> k;
		arv = vector<vector<int>>(n);
		visits = vector<bool>(n,false);
		vals = vector<int> (n);
		for (int &v: vals) cin >> v;

		for (int i = 0; i < n-1; i++) {
			int a,b;
			cin >> a >> b;
			arv[a-1].push_back(b-1);
			arv[b-1].push_back(a-1);
		}
		arv2 = vals;
		bool ndeu = false;
		for (int i = 0; i < n; i++){
			if (visits[i])
				continue;
			maxAmt = -INF;
			dfs_eq(i,vals[i],1);
			// cout << maxAmt << endl;
			if (maxAmt != INF && maxAmt%2){
				ndeu = true;
				break;
			}
		}

		if (!ndeu) {
			cout << "YES" << endl;
			continue;
		} else {
			int tot = 0;
			for (auto a : vals) tot ^= a;
			visits = vector<bool>(n,false);
			dfs_arv(0,tot);
			assert(arv2[0] == tot);
			int amttot=0;
			for (int v : arv[0]){
				amttot += v==tot;
			}
			if (!(amttot%2))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}


	}
	exit(0);
}
