#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		vector<int> vec(n);
		for(int &i: vec) cin >> i;
		sort(vec.begin(), vec.end());
		bool foi = true;
		for(int i = 0; i < n-1; i++) {
			if(vec[i+1] - vec[i]  <= 1)
				foi = false;
		}
		if(foi)
			cout << 1 << endl;
		else
			cout <<2 << endl;
	}
	exit(0);
}
