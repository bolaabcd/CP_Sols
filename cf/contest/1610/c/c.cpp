#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
vector<int> a;
vector<int> b;


bool bate(int k) {
	int amt = 0;
	for(int i = 0; i < n; i++) {
		if (a[i] >= k-amt-1 && b[i] >=amt)
			amt++;
	}
	return amt >=k;
}



int busca_bin(int l,int r) {
	if (l==r)
		return l;
	if(abs(l-r) == 1) {
		if(bate(r)) return r;
		else return l;
	}

	int meio = (l+r)/2;
	if(bate(meio))
		return busca_bin(meio,r);
	else
		return busca_bin(l,meio-1);
}


int main() { _
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		a = vector<int>(n);
		b = vector<int>(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		cout << busca_bin(0,n) << endl;

	}
	exit(0);
}
