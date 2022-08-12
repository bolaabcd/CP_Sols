#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n,m,k;
	double p;
	while(1){
		cin	>> n >> m >> k >> p;
		if(cin.eof())
			break;
		vector<vector<int>> gr(n);
		for(int i = 0; i < m; i++) {
			int a,b;
			cin >> a >> b;
			gr[--a].push_back(--b);
			gr[b].push_back(a);
		}

		vector<int> shots(n,0);
		int a;
		cin >> a;
		for(int i = 0; i < a; i++) {
			int pos;
			cin >> pos;
			pos--;
			shots[pos]++;
		}

		int from, to;
		cin >> from >> to;
		from--;
		to--;

		double probans = 0;
		vector<bool> added(n,false);
		// minimum number of shooters to kill to get there, where is "there"
		priority_queue<pair<int,int>> q;
		q.push({-shots[from],from});
		added[from] = true;

		while(!q.empty()) {
			auto pair = q.top();
			q.pop();
			int w = -pair.first, pos = pair.second;
			assert(added[pos]);

			if(w > k) {
				break;
			}

			if(pos == to){
				probans = pow(p,w);
				break;
			}

			for(int child:gr[pos]) {
				if(added[child])
					continue;
				q.push({-w-shots[child],child});
				added[child] = true;
			}
		}
		cout << fixed << setprecision(3);
		cout << probans << endl;

	}
	exit(0);
}
