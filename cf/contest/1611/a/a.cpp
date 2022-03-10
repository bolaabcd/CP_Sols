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

		bool allI = true;
		for(char c: s) {
			int v = int(c-'0');
			if(v%2==0){
				allI=false;
				break;
			}
		}

		if(int(s[s.length()-1]-'0')%2==0)
			cout << 0 << endl;
		else if(int(s[0]-'0')%2==0)
			cout << 1 << endl;
		else if(!allI)
			cout << 2 << endl;
		else
			cout << -1 << endl;
	}
	exit(0);
}
