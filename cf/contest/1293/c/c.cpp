#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<bool>> quad; 

/*

glgglggggg
glgglggglg

*/

void addBarrs(set<pair<pair<int,int>,pair<int,int>>> &s,int r,int c) {
	int o = !r;
	if (quad[o][c]) {
		s.emplace(make_pair(r,c),make_pair(o,c));
		s.emplace(make_pair(o,c),make_pair(r,c));
	}
	if (c > 0 && quad[o][c-1]) {
		s.emplace(make_pair(r,c+0),make_pair(o,c-1));
		s.emplace(make_pair(o,c-1),make_pair(r,c+0));
	}
	if (c < quad[0].size()-1 && quad[o][c+1]) {
		s.emplace(make_pair(r,c+0),make_pair(o,c+1));
		s.emplace(make_pair(o,c+1),make_pair(r,c+0));
	}
}

void remBarrs(set<pair<pair<int,int>,pair<int,int>>> &s, int r,int c) {
	int o = !r;
	if (quad[o][c]) {
		s.erase(make_pair(make_pair(r,c),make_pair(o,c)));
		s.erase(make_pair(make_pair(o,c),make_pair(r,c)));
	}
	if (c > 0 && quad[o][c-1]) {
		s.erase(make_pair(make_pair(r,c-0),make_pair(o,c-1)));
		s.erase(make_pair(make_pair(o,c-1),make_pair(r,c-0)));
	}
	if (c < quad[0].size()-1 && quad[o][c+1]) {
		s.erase(make_pair(make_pair(r,c+0),make_pair(o,c+1)));
		s.erase(make_pair(make_pair(o,c+1),make_pair(r,c+0)));
	}
}

int main() { _
	int n, q;
	cin >> n >> q;

	quad = vector<vector<bool>>(2,vector<bool>(n,false));

	set<pair<pair<int,int>,pair<int,int>>> barrs;
	for(int i = 0; i < q; i++) {
		int r,c;
		cin >> r >> c;
		if(!quad[r-1][c-1]){
			quad[r-1][c-1] = !quad[r-1][c-1];
			addBarrs(barrs,r-1,c-1);
		} else {
			remBarrs(barrs,r-1,c-1);
			quad[r-1][c-1] = !quad[r-1][c-1];
		}
		if(barrs.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


	exit(0);
}
