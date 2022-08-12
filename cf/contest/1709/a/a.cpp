#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int x;
	cin >> x;
	int ch[3];
	cin >> ch[0] >> ch[1] >> ch[2];
	
	if(ch[x-1] == 0) {
		cout << "No" << endl;
	} else if (ch[ch[x-1]-1] == 0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
