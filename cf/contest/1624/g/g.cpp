#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int t;
	cin >> t;
	while (t--)
	{
		int n,m;
		vector<vector<pair<int,int>>> gr;
		for(int i = 0; i < m; i++){
			int a,b,w;
			cin >> a >> b >> w;
			gr[a-1].push_back({b-1,w});
		}
		set<pair<int,int>> front;
		vector<bool> visit (n,false);
		int amtvis = 0;
		int ority = 0;
		
		front.insert({0,minor});
		while(amtvis < n) {
			int i = *front.begin();
			front.erase(i);

		}
	}
	
	exit(0);
}
