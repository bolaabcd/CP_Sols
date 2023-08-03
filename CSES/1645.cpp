#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n;
	cin >> n;
	vector<pair<int,int>> vals(n);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		vals[i] = {x,i};
	}
	vector<int> ans(n);
	sort(vals.begin(),vals.end());
	set<int> poss;
	vector<int> toadd;
	for(int i = 0; i < n; i++) {
		auto it = poss.upper_bound(-vals[i].s);//primeiro maior q -vals[i].s
		int v = 0;
		if(it != poss.end())
			v = -*it+1;
		ans[vals[i].s] = v;
		toadd.push_back(-vals[i].s);
		if(i < n and vals[i].f != vals[i+1].f) {
			for(int k : toadd)
				poss.insert(k);
			toadd.clear();
		}
	}

	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	exit(0);
}
