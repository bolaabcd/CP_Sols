#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 10000;

char memo[MAX][11];
int n;
int vec[MAX];

bool dp(int pos, int diff) {
	if(abs(diff) > 5)
		return false;
	if(pos == n)
		return true;
	if(memo[pos][diff+5] != -1) return memo[pos][diff+5];
	return (memo[pos][diff+5] = (dp(pos+1,diff-vec[pos]) || dp(pos+1,diff+vec[pos])));
}

bool solve() {
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> vec[i];
	memset(memo,-1,sizeof memo);
	return dp(0,0);
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
