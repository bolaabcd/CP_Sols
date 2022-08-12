#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int out[15];
int n,m;
set<pair<vector<int>,int>> jafoi;

// try to cut between p and p-1
bool trycut(vector<int> vec, int p) {
	if(jafoi.count({vec,p}))
			return false;
	jafoi.insert({vec,p});
	
	assert(p >= 0);
	assert(p < vec.size());
	if(vec.size() == m && p != 0) {
		for(int i = 0; i < m; i++)
			if(vec[i] != out[i])
				return false;
		return true;
	} else if (vec.size() < m)
		return false;
	else {
		vector<int> nvec(vec.size()-min(p,(int)vec.size()-p),0);
		for(int i = p, j = nvec.size()-1; i < vec.size() && j >= 0; i++, j--) {
			assert(i >= 0);
			assert(j >= 0);
			assert(i < vec.size());
			assert(j < nvec.size());
			nvec[j] += vec[i];
		}
		for(int i = p-1, j = nvec.size()-1; i >= 0 && j >= 0; i--, j--) {
			assert(i >= 0);
			assert(j >= 0);
			assert(i < vec.size());
			assert(j < nvec.size());
			nvec[j] += vec[i];
		}
		if(p == 0)
			assert(nvec.size() == vec.size());
		if(p == 0 && nvec.size() == m) {
			for(int i = 0; i < m; i++)
				if(nvec[i] != out[i])
					return false;
			return true;
		}
		for(int i = (p == 0); i < nvec.size(); i++) {
			if(trycut(nvec,i))
				return true;
		}
		return false;//nvec.size() == 1 && m == 1 && nvec[0] == out[0];
	}
}

bool solve() {
	jafoi.clear();
	cin >> n;
	if(cin.eof())
		return false;
	vector<int> inp(n);
	for(int &i: inp) cin >> i;
	cin >> m;
	for(int i = 0; i < m; i++) cin >> out[i];

	if(accumulate(inp.begin(),inp.end(),0) != accumulate(out,out+m,0)){
		cout << "N" << endl;
		return true;
	}
	
	for(int i = 0; i < n; i++) {
		if(trycut(inp,i)) {
			cout << "S" << endl;
			return true;
		}
	}
	
	cout << "N" << endl;
	return true;
}

int main() { _
	while(solve());
	
	exit(0);
}
