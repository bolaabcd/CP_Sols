#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int minops(string n, string v){
	int j = 0, rem = 0;
	for(int i = 0; i < n.size(); i++) {
		if(j < v.size() && n[i] == v[j])
			j++;
		else
			rem++;
	}
	return rem + v.size() - j;
}

int main() { _
	int t;
	cin >> t;
	while(t--) {
		string n;
		cin >> n;
		vector<string> pots;
		for(ll i = 1; i <= 1e18 ; i*=2){
			pots.push_back(to_string(i));
		}
		int mini = INF;
		
		for(auto s: pots) {
			// cout << minops(n,s) <<  " " << s << endl;
			mini = min(mini,minops(n, s));
		}
		cout << mini << endl;
	}
	exit(0);
}
