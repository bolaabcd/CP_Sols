#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	string s;
	cin >> s;
	int sum = 0, nint = 0;
	for(char c : s)
		if(c == '(')
			sum++;
		else if (c == ')')
			sum--;
		else
			nint++;
	if(nint == 1)
		assert(abs(sum) == 1);
	
	if (abs(sum) == nint)
		cout << "Yes" << endl;
	else if(abs(sum) == nint-1)
		assert(false);
	else {
		
	}
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
