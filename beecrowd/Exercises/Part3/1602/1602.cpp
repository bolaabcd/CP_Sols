#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int lim = 2e6+1;

int nhip[lim];

int main() { _
	// marcando primos até 2*10^6
	vector<bool> prims(lim,true);
	prims[0] = false;
	prims[1] = false;
	for (int i = 2; i*i < lim; i++) {
		if(!prims[i])
			continue;
		for (int j = i+i; j < lim; j += i)
			prims[j] = false;
	}

	// marcando num de divs até 2*10^6
	vector<int> ndivs(lim,1);
	ndivs[0] = 0;
	for (int i = 2; i < lim; i++) {
		for (int j = i; j < lim; j += i)
			ndivs[j]++;
	}

	// setando numero de hiperprimos
	for(int i = 1; i < lim; i++)
		nhip[i] = nhip[i-1] + prims[ndivs[i]];
	
	while(1) {
		int n;
		cin >> n;
		if(cin.eof())
			break;
		cout << nhip[n] << endl;
	}
	
	exit(0);
}

