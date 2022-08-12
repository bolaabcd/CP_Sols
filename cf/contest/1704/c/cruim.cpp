#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n,m;
set<int> bl, in;
//vector<int> in;

bool canspread() {
	for(int i: in)
		if((!bl.count((i-1+n)%n) && !in.count((i-1+n)%n)) || (!in.count((i+1)%n) && !bl.count((i+1)%n)))
			return true;
	return false;
}

void spread() {
	vector<int> toadd;
	for(int i: in) {
		if((!bl.count((i-1+n)%n) && !in.count((i-1+n)%n)))
			toadd.push_back((i-1+n)%n);
		if(!in.count((i+1)%n) && !bl.count((i+1)%n))
			toadd.push_back((i+1)%n);
	}
	for(int i : toadd)
		in.insert(i);
}

void bestblock() {
	int maxi = -INF, maxii;
	if(!bl.count((*in.begin()-1+n)%n) and !in.count((*in.begin()-1+n)%n)) {
		maxi = *in.begin() + n-*in.rbegin()-1;
		maxii = (*in.begin()-1+n)%n;
	} else if(!bl.count((*in.rbegin()+1)%n) and !in.count((*in.rbegin()+1)%n)) {
		maxi = *in.begin()+ n-*in.rbegin()-1;
		maxii = (*in.rbegin()+1)%n;
	}
	for(auto i = in.begin(); i != in.end(); i++) {
		auto nxt = i;
		nxt++;
		if(nxt == in.end())
			break;
		if(*nxt-*i-1 > maxi) {
			if(!bl.count((*i+1)%n) and !in.count((*i+1)%n)) {
				maxi = *nxt-*i-1;
				maxii = (*i+1)%n;
			} else if(!bl.count((*nxt-1+n)%n) and !in.count((*nxt-1+n)%n)) {
				maxi = *nxt-*i-1;
				maxii = (*nxt-1+n)%n;
			}
		}
	}
	assert(maxi != -INF);
	bl.insert(maxii);
}

void solve() {
	bl.clear();
	in.clear();
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int ai;
		cin >> ai;
		in.insert(ai-1);
	}
	//sort(in.begin(),in.end());
	int tot = 0;
	while(canspread()) {
		tot++;
		cout << tot << endl;
		bestblock();
		spread();
	}
	cout << in.size() << endl;
}

int main() { //_
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
