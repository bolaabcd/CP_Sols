#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int lim = 2e7+1;

int npot2fac[lim], npot2[lim];

int binmod2(int a, int b) { // a escolhe b modulo 2
	assert(npot2fac[a] >= npot2fac[a-b]+npot2fac[b]);
	return npot2fac[a] == npot2fac[a-b]+npot2fac[b];
}

int main() { _
	int a,b;
	cin >> a >> b;
	if(a == b){
		cout << '?' << endl;
		exit(0);
	}
	
	// marcando primos até 10^7
	vector<bool> prims(lim,true);
	prims[0] = false;
	prims[1] = false;
	for (int i = 2; i*i < lim; i++) {
		if(!prims[i])
			continue;
		for (int j = i+i; j < lim; j += i)
			prims[j] = false;
	}
	
	// marcando quantas potencias de 2 cada numero tem em si
	for(int k = 2; k < lim; k *= 2)
		for(int j = k; j <= lim; j += k)
			npot2[j]++;
	// marcando quantas potencias de 2 o fatorial de cada numero tem em si
	for(int i = 1; i < lim; i++)
		npot2fac[i] = npot2fac[i-1] + npot2[i];

	// contando quantos quadradinhos q e quantos primos p
	int q = abs(a-b), p = 0;
	for(int i = min(a,b); i <= max(a,b); i++)
		p += prims[i];

	if(p == 0)
		cout << "Bob" << endl;
	else if(binmod2(p+q-1,q))
		cout << "Alice" << endl;
	else
		cout << "Bob" << endl;
	
	exit(0);
}

