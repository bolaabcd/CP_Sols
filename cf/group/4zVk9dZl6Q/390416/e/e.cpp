#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n,k;
	cin >> n >> k;
	if(k == 1) {
		bool deu = false;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x
			if (!x) deu = true;
		}
		if(deu) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	exit(0);
}
