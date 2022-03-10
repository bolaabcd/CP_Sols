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
		int n,m;
		cin >> n >> m;

		if(m==n && m==1) {
			cout << 0 << endl;
		} else if (min(m,n)==1){
			cout << 1 << endl;
		} else
			cout << 2 << endl;
	}
	exit(0);
}
