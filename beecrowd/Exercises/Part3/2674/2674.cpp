#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int lim = 1e5+1;

int main() { _
	// marcando primos até 10^5
	vector<bool> prims(lim,true);
	prims[0] = false;
	prims[1] = false;
	for (int i = 2; i*i < lim; i++) {
		if(!prims[i])
			continue;
		for (int j = i+i; j < lim; j += i)
			prims[j] = false;
	}

	while(1) {
		string s;
		cin >> s;
		if(cin.eof())
			break;
		int n = atoi(s.c_str());

		if(prims[n]) {
			bool npr = false;
			for(char c: s)
				if(!(c == '2' || c == '3' || c == '5' || c == '7')){
					npr = true;
					break;
				}
			if(npr)
				cout << "Primo" << endl;
			else
				cout << "Super" << endl;
		} else {
			cout << "Nada" << endl;
		}
	}

	exit(0);
}

