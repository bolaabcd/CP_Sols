#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool dir(pii a, pii b, pii c) { // 1 se ta horario ou colinear
	pii v1 = {b.f-a.f,b.s-a.s}, v2 = {c.f-a.f,c.s-a.s};
	return (ll(v1.f)*ll(v2.s)-ll(v2.f)*ll(v1.s) >= 0LL);
}

int n;
vector<pair<int,int>> pts;
vector<pair<int,int>> stac,stactop;

void calch(){
	//sort(pts.begin(),pts.end());
	stac.clear();
	for(int i = 0; i < pts.size(); i++) {
		while(stac.size() >= 2 and !dir(stac[stac.size()-2],stac.back(),pts[i]))
			stac.pop_back();
		stac.push_back(pts[i]);
	}
	stactop.clear();
	for(int i = pts.size()-1; i >= 0; i--) {
		while(stactop.size() >= 2 and !dir(stactop[stactop.size()-2],stactop.back(),pts[i]))
			stactop.pop_back();
		stactop.push_back(pts[i]);
	}
	
	vector<pii> rev=stac;
	reverse(rev.begin(),rev.end());
	if(rev==stactop)
	    return;
	stac.pop_back();
	stactop.pop_back();
	stac.insert(stac.end(),stactop.begin(),stactop.end());

	//for(auto pa: stac)
	//	cout << pa.f << ' ' << pa.s << endl;
	//cout << "_______________" << endl;
	
	for(int i = 0; i < stac.size(); i++) {
		for(int j = pts.size()-1; j >= 0; j--)
			if(pts[j] == stac[i])
				pts.erase(pts.begin()+j);
	}
}

void solve() {
	pts.clear();
	pts.reserve(n);
	set<pii> remrep;
	for(int i = 0; i < n; i++){
		pii pi;
		cin >> pi.f >> pi.s;
		remrep.insert(pi);
	}
	for(auto pa: remrep)
		pts.push_back(pa);
	bool i;
	for(i = false; pts.size(); i = !i)
		calch();
	//cout << pts.size() << endl;
	//assert(!pts.size());
	if(pts.size())
	    i=!i;
	if(i)
		cout << "Take this onion to the lab!" << endl;
	else
		cout << "Do not take this onion to the lab!" << endl;
}

int main() { _
	while (1) {
		cin >> n;
		if(n == 0)
			break;
		solve();
	}
	exit(0);
}


/*
9
9 10
1 3
10 5
2 3
6 6
6 0
9 5
9 8
7 0
0


correto eh Do not take this onion to the lab!
ta dando
Take this onion to the lab!


*/

