#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool solve() {
	int n;
	cin >> n;
	int nps[10];
	memset(nps,0,sizeof nps);
	for(int i = 0; i < n; i++) {
		int p;
		cin >> p;
		nps[p-1] = (nps[p-1] + 1) % 2;
	}

	for(int i = 0; i < (1<<10); i++) {
		int diff = 0;
		for(int j = 0; j < 10; j++)
			if(i&(1<<j))
				diff += nps[j]*(j+1); 
			else
				diff -= nps[j]*(j+1);
		if (abs(diff) <= 5)
			return true;
	}
	return false;
}

int main() { _
	int t;
	cin >> t;
	while(t--)
		if(solve())
			cout << "Feliz Natal!" << endl;
		else
			cout << "Ho Ho Ho!" << endl;
	exit(0);
}
