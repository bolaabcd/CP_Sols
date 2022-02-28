#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	string s;
	cin >> s;
	int ans = 1, tmp = 1;
	for(char c : s) {
		if(c == 'R')
			tmp = 1;
		else
			tmp++;
		ans = max(ans,tmp);
	}
	cout << ans << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	exit(0);
}
