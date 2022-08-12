#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 101;

short n;
char memo[MAX][MAX][MAX];
char p1[MAX],p2[MAX],p3[MAX];

vector<char> ops(char a, char b, char c) {
	vector<char> ans;
	for(char i = 1; i < (1 << 3); i++) {
		char sum = 0;
		if (i&1) {
			if (a == n)
				continue;
			sum += p1[a]-'0';
		}
		if (i&2) {
			if (b == n)
				continue;
			sum += p2[b]-'0';
		}
		if (i&4) {
			if (c == n)
				continue;
			sum += p3[c]-'0';
		}
		if(!(sum%3))
			ans.push_back(i);
	}
	return ans;
}

bool dp(char a, char b, char c) {
	if(a == n && b == n && c == n)
		return true;
	if(memo[a][b][c] != -1)
		return memo[a][b][c];
	for(auto op : ops(a,b,c))
			if(dp(a+(op&1),b+((op&2)>>1),c+((op&4)>>2)))
				return (memo[a][b][c] = true);
	return (memo[a][b][c] = false);
}

int main() { _
	while(1) {
		cin >> n;
		if (n == 0)
			break;
		for(int i = 0; i < n; i++)
			cin >> p1[i] >> p2[i] >> p3[i];
		memset(memo,-1,sizeof(memo));
		cout << dp(0,0,0)<< endl;
	}
	exit(0);
}
