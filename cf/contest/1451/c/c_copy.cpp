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
		int n,k;
		cin >> n >> k;
		vector<int> as(26,0), bs(26,0);
		for(int i = 0; i < n; i++) {
			char c;
			cin >> c;
			as[int(c-'a')]++;
		}
		for(int i =0; i<n; i++) {
			char c;
			cin >> c;
			bs[int(c-'a')]++;
		}
		
		bool foi = true;
		int amts = 0;
		for(int i = 0; i < 26; i++) {
			if((as[i]+amts-bs[i])%k != 0){
				foi = false;
				break;
			}

			amts += as[i]-bs[i];
		}
		if (foi)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	exit(0);
}
/*
1
5 2
aaaaa
bbbca

No

*/