#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int ans[46];

void solve() {
	int s;
	cin >> s;
	cout << ans[s] << endl;
}

int main() { _
	/*for(int i = 0; i < 10; i++)
		ans[i] = i;
	for(int i = 10; i < 18; i++) {
		ans[i] =(11-i)*10+9;
	}*/
	for(int i = 0; i < 46; i++) {
		int j = i;
		vector<int> ans2;
		for(int k = 9; k > 0; k--) {
			if(j - k > 0) {
				j-= k;
				ans2.push_back(k);
			}
			else if (j == k) {
				ans2.push_back(k);
				break;
			}
		}
		int kk = 1;
		for(int k = 0; k < ans2.size(); k++){
			ans[i] += ans2[k]*kk;
			kk*=10;
		}
	}

	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
