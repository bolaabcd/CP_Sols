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

int main() { __
	ll n,m,s,d;
	cin >> n >> m >> s >> d;
	vector<ll> obs(n);
	for(ll i = 0; i < n; i++)
		cin >> obs[i];
	sort(obs.begin(),obs.end());
	ll p = 0, j = 0;
	vector<pair<string,ll>> ans;
	if(obs[0]-1 < s) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	while(j < n and p != m) {
		ans.pb({"RUN ",obs[j]-1-p});
		p += obs[j]-1-p;
		if(p == m)
			break;
		ll jmp = obs[j]+1-p;
		while(j+1 < n and obs[j+1] - obs[j]-1-1 < s) {
			j++;
			jmp = obs[j]+1-p;
		}
		j++;
		p += jmp;
		ans.pb({"JUMP ",jmp});
		if(jmp > d) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}
	if(p != m)
		ans.pb({"RUN ",m-p});
	for(auto [a,b] : ans)
		cout << a << b << endl;
	exit(0);
}
