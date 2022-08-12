#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	while(1){
		int n,m;
		cin >> n >> m;
		if(cin.eof())
			break;
		ll prod = 1;
		for(int i = 0; i < m; i++) {
			int ut, inut;
			cin >> ut >> inut >> inut;
			if(ut%2)
				prod*=ut;
		}
		cout << prod << endl;
	}
	exit(0);
}
