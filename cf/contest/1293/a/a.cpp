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
		int n,s,k;
		cin >> n >> s >> k;
		int poss=INF;
		vector<int> blocs(k);
		for(auto& b: blocs) cin >> b;
		sort(blocs.begin(), blocs.end());
		int i;
		for(i = 0; i < k; i++) {
			if(blocs[i] == s) {
				poss = i;
				break;
			}
		}

		for(i = s; i <= blocs[k-1] && poss+i-s >= 0 && poss+i-s < k && blocs[poss+i-s] == i; i++);
		if(i == n+1)
			i =  INF;
		
		int dfron = i-s;

		for(i = s; i >= blocs[0] && poss-(s-i) >= 0 && poss-(s-i) < k&& blocs[poss-(s-i)] == i; i--);
		if(i == 0)
			i = -INF;

		int dback = s-i;

		cout << min(dfron,dback) << endl;

	}
	exit(0);
}
