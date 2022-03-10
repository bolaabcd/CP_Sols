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
		string s;
		cin >> s;
		char c;
		cin >> c;
		bool da = false;
		for(int i = 0; i < s.length(); i+= 2) {
			if(s[i] == c)
				da = true;
		}
		if(da)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	exit(0);
}
