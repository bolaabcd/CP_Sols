#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1234;

vector<int> chang[MAX];
bool lamps[MAX];

int main() { _
	// interruptores e lampadas
	int n,m;
	cin >> n >> m;
	memset(lamps, false, sizeof(bool)*m);
	int ons;
	cin >> ons;
	if(ons == 0){
		cout << 0 << endl;
		exit(0);
	}
	for(int i = 0; i < ons; i++){
		int x;
		cin >> x;
		lamps[x-1] = true;
	}
	
	for(int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for(int j = 0; j < k; j++) {
			int assoss;
			cin >> assoss;
			assoss--;
			chang[i].push_back(assoss);
		}
	}
	
	int steps = 0;
	for(int twice = 0; twice < 2; twice++)
		for(int i = 0; i < n; i++){
			for(int j = 0; j < chang[i].size(); j++){
				lamps[chang[i][j]] = !lamps[chang[i][j]];
				if(lamps[chang[i][j]])
					ons++;
				else
					ons--;
			}
			steps++;
			if(ons == 0) {
				cout << steps << endl;
				exit(0);
			}
		}
	cout << -1 << endl;
	exit(0);
}
