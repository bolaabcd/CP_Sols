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
		for(int& i: vec) cin >> i, i--;
		vector<int> ans(n,-1);

		for(int i = 0; i < n; i++) {
			if(ans[i] == -1) {
				int amt = 1;
				for(int j = vec[i]; j != i; j=vec[j], amt++);
				for(int j = vec[i]; j != i; j=vec[j])
					ans[j] = amt;
				ans[i] = amt;
			}
		}

		for(auto i : ans) cout << i << " ", assert(i != -1);
		cout << endl;
	}
	exit(0);
}
