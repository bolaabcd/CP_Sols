#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1234;

int vec[MAX];
int setsiz[MAX];
int n;
// distance, edge (min,max)
set<pair<int, pair<int,int>>> edgsmin;
set<pair<int, pair<int,int>>> edgsmax;

int getset(int p) {
	for(;vec[p] != p; p = vec[p]);
	return p;
}

void unite(int a, int b) {
	assert(a == vec[a]);
	assert(b == vec[b]);
	if((setsiz[a] >= setsiz[b])) {
		vec[b]=a;
	} else {
		vec[a]=b;
	}
}

int getsum(bool mini, set<pair<int, pair<int,int>>>& edgtouse) {
	int sum = 0;
	iota(vec,vec+MAX,0);
	memset(setsiz, 1, MAX*sizeof(int));
	while (!edgtouse.empty()) {
		auto tr = *edgtouse.begin();
		edgtouse.erase(edgtouse.begin());
		int dist = tr.first, i = tr.second.first, j = tr.second.second;
		
		int si = getset(i), sj = getset(j);
		
		if(si == sj)
			continue;
		
		unite(si, sj);
		sum += mini ? dist : -dist;
	}
	return sum;
}

int main() { _
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		u--;
		v--;
		edgsmin.insert({w,{min(u,v),max(u,v)}});
		edgsmax.insert({-w,{min(u,v),max(u,v)}});
	}
	
	
	
	cout << getsum(false, edgsmax) << endl << getsum(true, edgsmin) << endl;
	
	
	exit(0);
}
