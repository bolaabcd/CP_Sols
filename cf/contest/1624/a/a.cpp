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
		vector<int> vec(n);
		int mini = INF, maxi = -INF;
		for(int& i: vec) cin >> i, mini = min(mini,i), maxi = max(i,maxi);

		cout << maxi - mini << endl;

	}
	exit(0);
}
