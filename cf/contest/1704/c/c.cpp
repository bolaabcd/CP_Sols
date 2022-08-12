#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n,m;
set<int> in;


vector<int> ints;

void getin() {
	int maxi;
	if(!in.count((*in.begin()-1+n)%n)) {
		maxi = *in.begin() + n-*in.rbegin()-1;
		ints.push_back(maxi);
	} else if(!in.count((*in.rbegin()+1)%n)) {
		maxi = *in.begin()+ n-*in.rbegin()-1;
		ints.push_back(maxi);
	}
	for(auto i = in.begin(); i != in.end(); i++) {
		auto nxt = i;
		nxt++;
		if(nxt == in.end())
			break;
		if(!in.count((*i+1)%n)) {
			maxi = *nxt-*i-1;
			ints.push_back(maxi);
		} else if(!in.count((*nxt-1+n)%n)) {
			maxi = *nxt-*i-1;
			ints.push_back(maxi);
		}
	}
}

void solve() {
	in.clear();
	ints.clear();
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int ai;
		cin >> ai;
		in.insert(ai-1);
	}
	getin();
	sort(ints.begin(),ints.end());
	int bias = 0, ans = n-m;
	for(int i = ints.size()-1; i >= 0; i--) {
		//cout << ans << ' ' << ints[i] << ' ' << bias<< endl;
		if(ints[i] > 2*bias + 2) {
			ans -=  1+2*bias;
			bias += 2;
		} else if (ints[i] == 2*bias + 2 or ints[i] == 2*bias+1) {
			ans -= ints[i]-1;
			bias += 1;
		} else
			ans -= ints[i];
	}
	cout << n-ans << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
