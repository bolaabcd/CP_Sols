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
	vector<int> vec;
	int j = 0;
	for(int i = 1; vec.size() < 2000 ; i++) {
		if (i%10 != 3 && i%3 != 0)
			vec.push_back(i);
	}
	while(t--) {
		int k;
		cin >> k;
		cout << vec[k-1] << endl;
	}
	exit(0);
}
