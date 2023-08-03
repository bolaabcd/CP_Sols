#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	double n,k;
	cin >> n >> k;
	double tot = 0;
	//double ant = 0;
	for(int i = 1; i <= k; i++) {
		//ant = pow(i,n)-ant;
		tot += i*((pow(i,n)-pow(i-1,n))/pow(k,n));
	}
	cout << fixed << setprecision(6);
	cout << tot << endl;
	exit(0);
}
