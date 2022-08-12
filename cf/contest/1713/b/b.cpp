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
	int ant = -INF, grow = 1;
	bool no = false;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(grow) {
			if(x < ant) 
				grow = 0;
		} else {
			if(x > ant) {
				no = true;
				
			}
		}


		ant = x;
	}
	if(no)
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
