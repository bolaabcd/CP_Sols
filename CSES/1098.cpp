#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n;
	cin >> n;
	int tot = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x %= 4;
		tot ^=x;
	}
	if(tot)
		cout << "first" << endl;
	else
		cout << "second" << endl;
}

int main() { __
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
