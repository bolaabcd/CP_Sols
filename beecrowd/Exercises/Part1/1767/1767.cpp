#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
int n;

// current position, remaining weight -> number of toys, total weight, total packages
tuple<int,int,int> memo[110][60];

// number of toys, weight
pair<int,int> packages[110];

tuple<int,int,int> dp(int p, int w) {
	if(w < 0)
		return {-INF,-1,-1};
	if(p == n)
		return {0,0,0};
	if(get<0>(memo[p][w]) != -1)
		return memo[p][w];

	// get vs dont get package at position p
	auto getthis = dp(p+1,w-packages[p].second), dontgetthis =  dp(p+1,w);
	get<0>(getthis) += packages[p].first;
	get<1>(getthis) += packages[p].second;
	get<2>(getthis) += 1;
	if (get<0>(getthis) >= get<0>(dontgetthis))
		return memo[p][w] = getthis;
	else 
		return memo[p][w] =  dontgetthis;
}

void solve() {
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> packages[i].first >> packages[i].second;
	memset(memo,-1, sizeof(memo));
	auto ans = dp(0,50);
	cout << get<0>(ans)  << " brinquedos" << endl
	<<	"Peso: " << get<1>(ans) << " kg" << endl
	<< "sobra(m) " << n-get<2>(ans) << " pacote(s)" << endl
	<< endl;
}

int main() { _
	int ttttt;
	cin >> ttttt;
	while(ttttt--) {
		solve();
	}
	exit(0);
}
