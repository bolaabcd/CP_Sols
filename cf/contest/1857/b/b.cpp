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
	string s;
	cin >> s;
	int n = s.size();
	if(s[0] >= '5') {
		cout << 1;
		for(int i = 0; i < n; i++)
			cout << 0;
		cout << endl;
		return;
	}
	int pos = -2;
	for(int i = 1; i < n; i++) {
		if(s[i] >= '5') {
			s[i] = '0';
			pos = i-1;
			break;
		}
	}
	if(pos != -2)
	for(int i = pos+1; i < n; i++)
		s[i] = '0';
	for(int i = pos; i >= 0; i--) {
		s[i]++;
		if(s[i] >= '5') {
			s[i] = '0';
		} else
			break;
	}
	if(s[0] == '0') {
		cout << 1;
		for(int i = 0; i < n; i++)
			cout << 0;
		cout << endl;
		return;
	} else
		cout << s << endl;
}

int main() { __
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}

