#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 256;

int s,b;

int x[MAX], bv[MAX];
int pat;

// plus one modular
int p1 (int p) {
	return (s+p+1)%s;
}

int tc = 1;

int mem[MAX][MAX/2][MAX];
bool marc[MAX];

int dp(int p, int bs) {
	// if has no more balls, wil 0 points
	if(bs == 0)
		return 0;
	// if reached the end without all balls, invalid
	if(marc[p] || marc[p1(p)])
		return INF;
	assert(bs > 0);
	assert(bs <= b);
	assert(p >= 0);
	assert(p < s);
	
	if(mem[p][bs][pat] != -1)
		return mem[p][bs][pat];
	
	// Both are false, if not we would have returned already.
	marc[p] = true;
	marc[p1(p)] = true;
	int mini = dp(p1(p1(p)),bs-1)+(x[p]+x[p1(p)])*bv[b-bs];//p and p+1, move two at once
	//cout << mini << endl;
	marc[p] = false;
	marc[p1(p)] = false;
	if(p == pat)
		return mem[p][bs][pat] = mini;
	return mem[p][bs][pat] = min(mini,dp(p1(p),bs));
}

bool sol() {
	cin >> s >> b;
	assert(!cin.eof());
	if(s == b && b == 0) return false;
	
	for(int i = 0; i < s; i++)
		cin >> x[i];
	for(int i = 0; i < b; i++)
		cin >> bv[i];
	
	int mini = INF;
	memset(mem,-1,sizeof(mem));
	for(pat = 0; pat < s; pat++){
		memset(marc,false,sizeof(marc));
		mini = min(mini,dp(pat,b));
	}
	
	assert(mini != -INF);
	cout << -mini << endl;
	
	return true;
}

int main() { _
	while(sol())tc++;
	exit(0);
}
