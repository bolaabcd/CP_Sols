#include <bits/stdc++.h>

using namespace std;

// #define _ ios_base::sync_with_stdio(0);cin.tie(0);
// #define endl '\n'

int perg(int val) {
	cout << "+ " << val << endl;
	cout.flush();
	int ans;
	cin >> ans;
	return ans;
}

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
int n;
vector<pair<int,int>> pans;
int mults = 0;

// True se eh <=, false se for >
bool querry(int val) {
	int a = perg(val + mults*n);
	pans.push_back({val,a});
	
	mults++;
}

void saida(int val) {
	cout << "! " << val << endl;
	cout.flush();
}

int bb(int l,int r) {
	if(l == r)
		return l;
	int m = (l+r)/2;
	if(querry(m))
		return bb(l,m);
	else
		return bb(m+1,r);
}

int main() { //_
	cin >> n;

	saida(bb(0,n-1));
	
	exit(0);
}
