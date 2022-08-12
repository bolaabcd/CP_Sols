#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	string msg, crib;
	cin >> msg >> crib;

	// assert(msg.length() >= crib.length());

	int nposs = msg.size() - crib.size()+1;
	int nposscp = nposs;
	for(int i = 0; i < nposscp; i++) {
		for(int j = 0; j < crib.size(); j++) {
			// assert(j+i < msg.size());
			if(crib[j] == msg[i+j]){
				nposs--;
				break;
			}
		}
	}

	cout << nposs << endl;
	exit(0);
}
