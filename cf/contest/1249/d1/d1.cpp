#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 210;

int n,k;


void atualiza(multiset<tuple<int,int,int,int>> &segs, vector<int> &amts) {
	multiset<tuple<int,int,int,int>> copia;
	for(auto tup : segs) {
		int l = get<1>(tup), r = get<2>(tup);
		int amt = 0;
		for(int j = l; j <= r; j++) {
			if(amts[j] > k)
				amt++;
		}
		// get<0>(tup) = -amt;
		tuple<int,int,int,int> tupla = {-amt,l,r,get<3>(tup)};
		copia.insert(tupla);
	}
	// sort(copia.begin(), copia.end());
	segs = copia;
}

void tira (tuple<int,int,int,int> tup, vector<int> &amts) {
	int l = get<1>(tup), r = get<2>(tup);
	for(int i = l; i <= r; i++) {
		assert(amts[i] > 0);
		amts[i]--;
	}
}

bool ok(vector<int> &amts) {
	for(int i  = 0; i < amts.size(); i++)
		if(amts[i] > k) return false;
	return true;
}

int main() { _
	cin >> n >> k;
	// -numero de bad points, li, ri, indice
	multiset<tuple<int,int,int,int>> segs;
	vector<int> amts(MAX,0);

	for(int i = 0; i < n; i++) {
		int li,ri;
		cin >> li >> ri;
		for(int j = li-1; j < ri; j++)
			amts[j]++;
		tuple<int,int,int,int> el = {0,li-1,ri-1,i+1};
		segs.insert(el);
		// get<0>(segs[i]) = 0;
		// get<1>(segs[i]) = li-1;
		// get<2>(segs[i]) = ri-1;
		// get<3>(segs[i]) = i+1;
	}

	atualiza(segs,amts);

	set<int> ans;
	while(!ok(amts)){
		int ind = get<3>(*segs.begin());
		assert(!ans.count(ind));
		ans.insert(ind);
		tira(*segs.begin(),amts);
		segs.erase(segs.begin());
		atualiza(segs,amts);
	}


	cout << ans.size() << endl;
	for(int i: ans) cout << i << " ";
	cout << endl;

	exit(0);
}
