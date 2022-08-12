#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXI = 500;

int n;
int arr[2*MAXI];
int memo[2*MAXI][2*MAXI][2];

int dp(int l, int r, bool itsme) {
	if(l > r)
		return 0;
	if(memo[l][r][itsme] != -1)
		return memo[l][r][itsme];

	if(itsme)
		return memo[l][r][itsme] = max(
			dp(l+1,r,false) + !(arr[l]%2),
			dp(l,r-1,false) + !(arr[r]%2)
		);
	else
		return memo[l][r][itsme] = min(
			dp(l+1,r,true),
			dp(l,r-1,true)
		);
}

int main() { _
	while(1) {
		cin >> n;
		if (n == 0)
			break;
		for(int i = 0; i < 2*n; i++)
			cin >> arr[i];
		memset(memo,-1,sizeof(memo));
		cout << dp(0,2*n-1,true) << endl;
	}
	exit(0);
}
