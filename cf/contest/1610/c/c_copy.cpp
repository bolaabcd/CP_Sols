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
const int MAXP = 2e5+10, MAXK=2e2+10;
int res[MAXP][MAXK];

// vector<int> ac,bc;
vector<bool> pego;
int kat;


bool bate(int i, int k) {
	if (k == 0) {
		int foi = 0;
		for(int j = 0; j < n; j++) {
			if(pego[j]){
				if(a[j]-(kat-foi-1) < 0)
					return res[i][k] = false;
				if(b[j]-foi < 0)
					return res[i][k] = false;
				foi++;
			}
		}
		return res[i][k] = true;
	}
	if (i >= n) return res[i][k] = false;
	if (res[i][k] != -1) return res[i][k];

	pego[i] = false;
	if(bate(i+1,k))
		return res[i][k] = true;
	
	pego[i] = true;

	return res[i][k] = bate(i+1,k-1);
}



int busca_bin(int l,int r) {
	if (l==r)
		return l;
	memset(res,-1,sizeof res);
	pego = vector<bool>(n,false);
	// ac = a;
	// bc = b;
	if(abs(l-r) == 1) {
		kat = r;
		if(bate(0,r)) return r;
		else return l;
	}

	int meio = (l+r)/2;
	kat = meio;
	if(bate(0,meio))
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
