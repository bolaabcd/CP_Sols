#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n;
	cin >> n;
	vector<ll> vec(n);
	for(ll&i:vec)cin>>i;
	bool tem0=false;
	for(int i = 0; i < n; i++) {
		while(vec[i]%10 != 0 and vec[i]%10 != 2)
			vec[i] += vec[i]%10;
		if(vec[i]%10 == 0)tem0=true;
	}
	if(tem0) {
		for(int i = 1; i < n; i++)
			if(vec[i]!=vec[i-1]) {
				cout << "No" << endl;
				return;
			}
		cout << "Yes" << endl;
		return;
	}

	int imp = (vec[0]/10)%2;
	for(int i = 1; i < n; i++) {
		if (imp != ((vec[i]/10)%2)) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
