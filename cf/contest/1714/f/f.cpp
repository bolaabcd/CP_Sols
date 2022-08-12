#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
int v[3];

void eq(int r,int s, int t) {
	if(v[r] + v[s] >= n)
		cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		int x = 3;
		
	}
}

void solve() {
	cin >> n >> v[0] >> v[1] >> v[2];
	if(a + b == c) eq(0,1,2);
	else if (a+c == b)eq(0,2,1);
	else if (b+c == a)eq(1,2,0);
	else if (a+b > c)ma(0,1,2);
	else if(a+c>b)ma(0,2,1);
	else ma(1,2,0);
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
