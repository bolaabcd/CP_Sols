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
		for(int&i:vec)cin>>i;
		sort(vec.begin(),vec.end());
		cout << vec[n-1]+vec[n-2]-vec[0]-vec[1] << endl;
	}
	exit(0);
}
