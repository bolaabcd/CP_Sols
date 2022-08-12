#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	string s,t;
	cin >> t;
	s = "ZELDA";
	//cout << ((int)'a') << ' ' << ((int)'A') << endl;
	int j = 0;
	for(char c: t){
		if (c >= 'a')
			c = (c - 'a')+'A';
		if (c != s[j])
			j = 0;
		if (c == s[j])
			j++;
		if(j == s.size()){
			cout << "Link Bolado" << endl;
			exit(0);
		}
	}

	cout << "Link Tranquilo" << endl;
	exit(0);
}
