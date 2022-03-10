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
		int n;
		cin >> n;
		vector<int> fa(n);
		for(int &i: fa) cin >> i;
		vector<int> ans;
		for(int i = n-1; i >=0; i--) {
			int p = -1;
			for(int j = 0; j <= i; j++)
				if(fa[j] == i+1){
					p = j;
					break;
				}
			assert(p != -1);
			int ncic = (p+1) % (i+1);
			ans.push_back(ncic);
			vector<int> cop = fa;
			for(int j = 0; j <= i; j++) {
				fa[j] = cop[(j+ncic)%(i+1)];
			}
		}
		assert(ans.size() == n);
		for(int i = 0; i < n; i++)
			assert(fa[i] == i+1);
		reverse(ans.begin(), ans.end());
		for(int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	exit(0);
}
