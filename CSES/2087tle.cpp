#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 3000+10;

ll n,k;
ll arr[MAX];
ll memo[MAX][MAX]; // tem uma casa na posicao i, falta colocar k casas na frente (atras ja computou), (i,k)
ll pirup[MAX][MAX], pirdown[MAX][MAX]; // no up o segundo eh maior, no down o segundo eh menor, o primeiro eh sempre onde tem casa
// up vai crescendo 1234, down vai caindo 4321

ll piram(int i, int j) { // de i pra j, com i e j sendo casas
	return pirup[i][i+(j-i)/2] + pirdown[j][i+(j-i+1)/2];
}

int main() { __
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			pirup[i][j] = pirup[i][j-1] + (j-i)*arr[j];
	
	for(int i = 0; i < n; i++)
		for(int j = i-1; j >= 0; j--)
			pirdown[i][j] = pirdown[i][j+1] + (i-j)*arr[j];

	for(int i = 0; i < n; i++) {
		memo[i][0] = pirup[i][n-1];
	}
	
	for(int kk = 1; kk < k; kk++) {
		for(int i = 0; i < n; i++) {
			ll mini = LINF;
			for(int j = i+1; j < n; j++)
				mini = min(mini,piram(i,j) + memo[j][kk-1]);
			memo[i][kk] = mini;
		}
	}
	
	ll ans = LINF;
	for(int i = 0; i < n; i++)
		ans = min(ans,memo[i][k-1]+pirdown[i][0]);

	cout << ans << endl;
	exit(0);
}
