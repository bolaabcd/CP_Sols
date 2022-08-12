#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef unsigned long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main() { _
	ll n,x;
	cin >> n >> x;
	string s;

	for(int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if(c == 'U' && s.size() > 0 && s[s.size()-1] != 'U') {
			s.pop_back();
		} else {
			s.push_back(c);
		}
	}
	for(int i = 0; i < s.size(); i++) {
		char c;
		c = s[i];
		if(c == 'U')
			x/=2;
		else if(c == 'L')
			x*=2;
		else
			x=x*2+1;
	}

	cout << x << endl;
	exit(0);
}
