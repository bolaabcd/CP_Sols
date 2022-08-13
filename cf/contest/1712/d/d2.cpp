#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int e9 = 1e9;
int n,k;
/*
bool good(int val, priority_queue<pair<int,int>> pq, vector<int> &vec) {
	vector<pair<int,int>> backup;
	bool ans = false;
	while(!pq.empty() and -pq.top().first == val) {
		int pos = pq.top().second;
		backup.push_back(pq.top());
		pq.pop();
		if(pos > 0 and vec[pos-1] >= val) {
			ans = true;
			break;
		} else if (pos < n-1 and vec[pos+1] >= val) {
			ans = true;
			break;
		}
	}
	for(auto pa : backup)pq.push(pa);
	return ans;
}*/

void solve () {
	cin >> n >> k;
	int ko = k;
	vector<int> vec(n);
	int mini = INF, amtmini = 0;;
	priority_queue<pair<int,int>> pq; // -val, pos
	queue<int> minipos;
	for(int i = 0; i < n; i++){
		cin>>vec[i];
		if(vec[i] < mini) {
			mini = vec[i];
			amtmini = 0;
		}
		if(vec[i] == mini) {
			amtmini++;
		}
	}
	if(k == n) {
		cout << e9 << endl;
		return;
	}
	if(k == n-1) {
		if(n == 2) {
			cout << max(vec[0],vec[1]) << endl;
			return;
		} else {
			int maxi = -INF;
			for(int i = 0; i < n; i++)
				maxi = max(maxi, vec[i]);
			cout << min(e9,2*maxi) << endl;
			return;
		}
	}
	for(int i = 0; i < n; i++) {
		if(vec[i] > mini){
			pq.push({-vec[i],i});
		} else
			minipos.push(i);
	}
	priority_queue<pair<int,int>> mamis; // val and i-pos
	//int mami = -INF;
	for(int i = 0; i < n-1; i++) {
		//mami = max(mami, min(vec[i],vec[i+1]);
		mamis.push({min(vec[i],vec[i+1]),i});
	}
	set<int> del;
	for(;k>0;k--) {
		int val, pos;
		if(pq.empty()) {
			val = INF;
			pos = -1;
		} else {
			val = -pq.top().first;
			pos = pq.top().second;
		}
		while(!mamis.empty() and (vec[mamis.top().second+1] == e9 or vec[mamis.top().second] == e9 or del.count(mamis.top().second+1) or del.count(mamis.top().second) or mamis.top().first == mini)) {
			int posi = mamis.top().second;
			mamis.pop();
			if(vec[posi+1] == e9 or vec[posi] == e9) {
				mamis.push({min(vec[posi],vec[posi+1]),posi});
			}
		}
		if(!mamis.empty() and mamis.top().first < 2*mini and mamis.top().first != mini) {
			del.insert(pos);
			vec[pos] = e9;
			pq.pop();
		} else { // delete mini
			if(amtmini) {
				amtmini--;
				del.insert(minipos.front());
				vec[minipos.front()] = e9;
				minipos.pop();
			}
			if(!amtmini && pos != -1) {
				assert(minipos.empty());
				mini = val;
				amtmini = 0;
				while(!pq.empty() && -pq.top().first == val) {
					amtmini++;
					minipos.push(pq.top().second);
					pq.pop();
				}
			}
		}
	}
	assert(del.size() == ko);
	int diam = -INF;
	for(int i = 0; i < n; i++) {
		if(!del.count(i))
			diam = max(diam,min(2*mini,vec[i]));
	}
	if(diam == -INF)
		diam = e9;
	cout << min(diam,e9) << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
