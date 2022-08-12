#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1000;

int n,k,v;
double dam[MAX], hp[MAX];

double memo[MAX][101];
double dp(int pos, int mana) {
	if(mana < 0)
		return INF;
	if (pos == n)
		return 0;
	if(memo[pos][mana] != -1)
		return memo[pos][mana];

	return memo[pos][mana] = min(
		dp(pos+1,mana)  + hp[pos]/v,
		dp(pos+1,mana-1)+ hp[pos]/(v+dam[pos])
	);
}

int main() { _
	cout.precision(4);
	cout << fixed;
	while(1) {
		cin >> n >> k >> v;
		if(cin.eof())
			break;
		for(int i = 0; i < n; i++)
			cin >> hp[i] >> dam[i];

		for(int i = 0; i < MAX; i++)
			for(int j = 0; j < 101; j++)
				memo[i][j] = -1;
		cout << dp(0,k) << endl;
	}
	exit(0);
}
