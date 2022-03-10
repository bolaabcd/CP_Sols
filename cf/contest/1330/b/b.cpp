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
	while (t--) {
		int n;
		cin >> n;
		vector<int> vec(n);
		for(int& v: vec) cin >> v;
		vector<bool> ida(n,false);
		vector<bool> volta(n,false);

		set<int> tmp;
		for (int i = 0; i < n; i++) {
			tmp.insert(vec[i]);
			int finalv = *tmp.rbegin();
			if(finalv == i+1 && tmp.size() == i+1) {
				ida[i] = true;
			}
		}
		tmp.clear();
		for (int i = n-1; i >= 0; i--) {
			tmp.insert(vec[i]);
			int finalv = *tmp.rbegin();
			if(finalv == n-i && tmp.size() == n-i) {
				volta[i] = true;
			}
		}
		vector<pair<int,int>> anss;
		for (int i = 0; i < n-1; i++) {
			if(ida[i] && volta[i+1]) {
				anss.emplace_back(i+1,n-i-1);
			}
		}
		cout << anss.size() << endl;
		for(auto& an:anss) {
			cout << an.first << " " << an.second << endl;
		}
	}
	exit(0);
}
