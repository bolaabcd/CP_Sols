#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int lim = 1e7+5e6+5e5; // 10^6-esimo primo eh +- isso

int main() { _
	// pegando 10^6+algo primeiros primos
	vector<bool> prims(lim,true);
	for (int i = 2; i*i < lim; i++) {
		if(!prims[i])
			continue;
		for (int j = i+i; j < lim; j += i)
			prims[j] = false;
	}
	int ttt;
	cin >> ttt;
	while(ttt--) {
		int n;
		cin >> n;

		vector<int> vals(n);
		for(int& i: vals) cin >> i;
		sort(vals.begin(), vals.end());
		vals.push_back(INF);

		// imprime primeiro primo (i) que nao ta em vals (j)
		for(int i = 1, j = 0; i <= lim; i++) {
			if(!prims[i])
				continue;
			while(vals[j] < i)
				j++;
			if(vals[j] != i) {
				cout << i-1 << endl;
				break;
			}
			j++;
		}

	}
	
	exit(0);
}

