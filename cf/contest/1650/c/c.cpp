#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int t;
	cin >> t;
	while(t--) {
		int n,m;
		cin >> n >> m;
		// peso, posicao, i
		vector<tuple<int,int,int>> vec;
		for(int i = 0; i < m; i++) {
			int x,w;
			cin >> x >> w;
			vec.push_back({w,x,i+1});
		}
		sort(vec.begin(), vec.end());

		// posicao, peso, i
		vector<tuple<int,int,int>> tvec;
		ll soma = 0;
		for(int i = 0; i < 2*n; i++){
			tvec.push_back({get<1>(vec[i]),get<0>(vec[i]), get<2>(vec[i])});
			soma +=get<0>(vec[i]);
		}

		sort(tvec.begin(), tvec.end());

		cout << soma << endl;
		for(int i = 0; i < n; i++) {
			cout << get<2>(tvec[i]) << " " << get<2>(tvec[2*n-i-1]) << endl;
		}
		cout << endl;


	}
	exit(0);
}
