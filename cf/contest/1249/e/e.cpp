#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<ll>> vec(3e5,vector<ll>(2,-1));
ll n,c;


ll dp(int pos, bool pago, vector<ll> & as, vector<ll> & bs) {
	if(pos == 0 && pago)
		return vec[pos][pago] = INF;
	if(pos == 0)
		return vec[pos][pago] = 0;

	if(vec[pos][pago] != -1)
		return vec[pos][pago];

	if(pago)
		return vec[pos][pago] = min(dp(pos-1,true,as,bs)+bs[pos],dp(pos-1,false,as,bs)+bs[pos]+c);
		// return vec[pos][pago] = dp(pos-1,true,as,bs)+bs[pos];
	else
		return vec[pos][pago] = min(dp(pos-1,true,as,bs)+as[pos],dp(pos-1,false,as,bs)+as[pos]);
}


int main() { _
	cin >> n >> c;
	vector<ll> as(n), bs(n);
	for(int i = 1; i < n; i++)
		cin >> as[i];
	for(int i = 1; i < n; i++)
		cin >> bs[i];
	as[0] = bs[0] = 0;


	for(int i = 0; i < n; i++) {
		dp(i,false,as,bs);
		dp(i,true,as,bs);		
	}

	
	for(int i = 0; i < n; i++) {
		cout << min(vec[i][0],vec[i][1]) << " ";
	}
	cout << endl;

	exit(0);
}
