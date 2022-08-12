#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1000;

int n, p;
pair<int,int> spells[MAX];
int memo[2001][MAX];

int dp(int hp, int pos) {
	if(hp <= 0)
		return 0;
	if (pos == n)
		return INF;
	if(memo[hp][pos] != -1)
		return memo[hp][pos];
	else
		return memo[hp][pos] = min(
			dp(hp,pos+1),
			dp(hp-spells[pos].first,pos+1)+spells[pos].second
		);
}

int main() { _
	while(1) {
		cin >> n >> p;
		if(cin.eof())
			break;
		for(int i = 0; i < n; i++)
			cin >> spells[i].first >> spells[i].second;
		memset(memo,-1,sizeof memo);
		cout << ((dp(p,0) == INF)?-1: dp(p,0)) << endl;
	}
	exit(0);
}
