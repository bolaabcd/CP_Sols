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
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int&i:vec) {
		cin>>i;
		i--;
	}
	vector<vector<pii>> ans;
	vector<bool> mark(n,false);
	for(int i = 0; i < n; i++)
		if(!mark[i] and vec[i] != i) {
			if(ans.size() == 0)
				ans.pb({});
			vector<int> inds;
			int p = i;
			do {
				inds.pb(p);
				mark[p] = true;
				p = vec[p];
			} while(p != i);
			if(inds.size() == 2) {
				ans[0].pb({i,vec[i]});
				swap(vec[i],vec[vec[i]]);
			}
			for(int j = 0; j < (inds.size()+1)/2-1; j++) {
				ans[0].pb({inds[j],inds[inds.size()-2-j]});
				swap(vec[inds[j]],vec[inds[inds.size()-2-j]]);
			}
		}
	for(int i = 0; i < n; i++)
		if(i != vec[i]) {
			if(ans.size() == 1)
				ans.pb({});
			ans[1].pb({i,vec[i]});
			swap(vec[i],vec[vec[i]]);
		}

	cout << ans.size() << endl;
	for(auto& v: ans) {
		cout << v.size() << endl;
		for(auto [a,b]: v)
			cout << a+1 << ' ' << b+1 << endl;
	}
	exit(0);
}
