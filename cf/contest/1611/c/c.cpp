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
		for(int& v: vec) cin >> v;
		reverse(vec.begin(),vec.end());

		if(vec[0] != n && vec[n-1] != n) {
			cout << -1 << endl;
			continue;
		}

		for(int v:vec) cout << v << " ";
		cout << endl;
	}
	exit(0);
}

/*
6
3
1 2 3
3
1 3 2
3
2 3 1
3
2 1 3
3
3 1 2
3
3 2 1

3 2 1
-1
-1
3 1 2
2 1 3
1 2 3

*/