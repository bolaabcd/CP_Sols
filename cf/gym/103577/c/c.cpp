#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	while(1) {
		string s;
		cin >> s;
		if(cin.eof()) break;
		int n = s.size();
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				string s2 = s.substr(i,j-i+1);
				
			}
		}
	}
	exit(0);
}
