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
		int i = 0, j = s.size()-1, sl = 0, sr = 0;
		while(i!=j){
			if(s[i] == '(') {
				sl++;
				i++;
				continue;
			}
			if(s[i] == ')') {
				sl--;
				i++;
				continue;
			}
			if(s[i] == '?' && sl == 0) {
				s[i] = '(';
				continue;
			}

			if(s[j] == '(') {
				sr++;
				j--;
				continue;
			}
			if(s[j] == ')') {
				sr--;
				j--;
				continue;
			}
			if(s[j] == '?' && sr == 0) {
				s[j] = ')';
				continue;
			}
			assert(sl > 0);
			assert(sr < 0);
			break;
		}
		int nint2 = 0, sum2 = 0;
		for(char c: s)
			if(c == '(')
				sum2++;
			else if (c == ')')
				sum2--;
			else
				nint2++;
		
		if(i == j || nint2 == abs(sum2))
			cout << "Yes" << endl;
		else if (sl == sr || !sum2)
			cout << "No" << endl;
		else {
			if(nint2%2)
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
			//assert(false);
		}
	}
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
