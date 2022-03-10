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
		string n,k;
		cin >> n >> k;
		if( k == "1"){
			int v = n[0] - '0';
			ll digs = 0;
			for(int i = 0; i < n.size(); i++) {
				digs += v * pow(10,i);
			}
			ll ene = atoll(n.c_str());
			if (digs < ene){
				if (v == 9)
					cout << 9;
				for(int i = 0; i < n.size(); i++) {
					if(v != 9)
						cout << v+1;
					else
						cout << v;
				}
				cout << endl;
			} else {
				for(int i = 0; i < n.size(); i++) {
					cout << v;
				}
				cout << endl;
			}
		} else {
			
		}
	}
	return 0;
}
