#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve () {
	int n;
	cin >> n;
	vector<vector<int>> vec(2);
	int amtz = 0;
	for(int i = 0; i < n; i++) {
		int ai;
		cin >> ai;
		if(ai != 0)
			vec[0].push_back(ai);
		else
			amtz++;
	}
	int x = 0;
	while(vec[x].size() > 1) {
		int ant = -1;
		sort(vec[x].begin(),vec[x].end());
		vec[!x].clear();
		if(amtz > 0) {
			amtz--;
			vec[!x].push_back(vec[x][0]);
		}
		for(int i : vec[x]) {
			if(ant != -1) {
				if(i-ant > 0)
					vec[!x].push_back(i-ant);
				else
					amtz++;
			}
			ant = i;
		}
		x = !x;
	}
	if(vec[x].size() == 0)
		cout << 0 << endl;
	else
		cout << *vec[x].begin() << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
