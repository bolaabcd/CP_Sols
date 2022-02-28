#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// Order Statistic Set
//
// Funciona do C++11 pra cima

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
	
// para declarar:
// -valor, pos
ord_set<pair<int,int>> os;

vector<pair<int,int>> a;

int main() { _
	int n,m;
	cin >> n;
	a.resize(n);
	
	for(int i = 0; i < n; i++) {
		int v;
		cin >> v;
		a.push_back({-v,i});
	}

	sort(a.begin(),a.end());

	cin >> m;
	// k, pos, posicao nas querries, resposta
	vector<tuple<int,int,int>> kp;
	for(int i = 0; i < m; i++) {
		int k,pos;
		cin >> k >> pos;
		kp.push_back({k,pos-1,i});
	}

	sort(kp.begin(),kp.end());

	vector<int> ans(m,-1);

	for(int i = 0, j = 0; i < n && j < m; i ++) {
		os.insert({a[i].second,-a[i].first});
		while(get<0>(kp[j]) == i+1) {
			ans[get<2>(kp[j])] = os.find_by_order(get<1>(kp[j]))->second;
			j++;
			if(j >= m)
				break;
		}
	}

	for(int j = 0; j < m; j++) {
		cout << ans[j] << endl;
	}

	exit(0);
}
