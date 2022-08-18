#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	short n;
	cin >> n;
	vector<short> a(n);
	for(short&i:a)cin>>i;
	short m = 0;
	for(short&i:a)m |= i;
	a.push_back(0);
	unordered_set<short> asold, asnew; // possible values
	//map<pair<short,short>,short> mp; // from position in as and value to number of steps
	//vector<short> vecmp((n+1)*(m+1)+1,-1); // i*m+val
	vector<short> oldmp, newmp(m+1,-1);
	asnew.insert(a[0]);
	newmp[a[0]] = 0; 
	for(int i = 1; i < n+1; i++) {
		asold = asnew;
		asnew.clear();

		oldmp = newmp;
		newmp.clear();
		newmp.resize(m+1,-1);
		asnew.insert(a[i]);
		for(short val : asold) {
			int mini = INF;
			//if(mp.count({i,a[i]}))
			//	mini = mp[{i,a[i]}];
			//mp[{i,a[i]}] = min(mini,(val != 0) + mp[{i-1,val}]);
			if(newmp[a[i]] != -1)
				mini = newmp[a[i]];
			newmp[a[i]] = min(mini,(val != 0) + oldmp[val]);

			asnew.insert(val ^ a[i]);
			mini = INF;/*
			if(mp.count({i,val^a[i]}))
				mini = mp[{i,val^a[i]}];
			mp[{i,val^a[i]}] = min(mini,(val != 0) + mp[{i-1,val}]);
			mp.erase({i-1,val});
			*/
			if(newmp[(val^a[i])] != -1)
				mini = newmp[(val^a[i])];
			newmp[(val^a[i])] = min(mini,(val != 0) + oldmp[val]);
		}
	}
	cout << newmp[0] << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
