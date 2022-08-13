#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool ok(vector<int> &vec) {
	for(int i = 1; i < vec.size(); i++) {
		if(vec[i-1] > vec[i])
			return false;
	}
	return true;
}

void solve () {
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int&i:vec)cin>>i;
	set<int> rems;
	while(!ok(vec)) {
		int pos = -1;
		for(int i = n-1; i >= 1; i--) {
			if(vec[i-1] > vec[i]) {
				pos = i;
				break;
			}
		}
		for(int i = 0; i < pos; i++) {
			rems.insert(vec[i]);
			vec[i] = 0;
		}
		for(int i = pos; i < n; i++)
			if(rems.count(vec[i]))
				vec[i] = 0;
	}
	cout << rems.size()-rems.count(0) << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
