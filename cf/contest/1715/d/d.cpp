#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n,q;
	cin >> n >> q;
	vector<tuple<int,int,int>> restr(q);
	for(auto &[i,j,x]: restr) {
		cin >> i >> j >> x;
		i--;
		j--;
		if(i > j)
			swap(i,j);
	}

	sort(restr.begin(),restr.end());

	vector<int> ans(n,0), probs(n,0);
	for(int b = 0; b < 31; b++) {
		for(auto [i,j,x] : restr)		
			if(!((x>>b)&1)) {
				probs[i] |= (1<<b);
				probs[j] |= (1<<b);
			}
		for(auto [i,j,x] : restr) {
			if(((x>>b)&1) and ((probs[i]>>b)&1))
				ans[j] |= (1<<b);
			if(((x>>b)&1) and ((probs[j]>>b)&1))
				ans[i] |= (1<<b);
		}
		
		for(auto [i,j,x] : restr)
			if(((x>>b)&1) and !((ans[i]>>b)&1) and !((ans[j]>>b)&1))
				ans[j] |= (1<<b);
	//	for(auto [i,j,x] : restr)
	//		if((x>>b)&1)
	//			if(!((ans[j]>>b)&1))
	//				ans[i] |= 1;
	}

	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;

	exit(0);
}
