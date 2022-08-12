#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool tem (vector<int>&vec, int val) {
	for(int i:vec)
		if(i==val)return true;
	return false;
}

void solve(int n) {
	vector<vector<int>> trie(26);
	vector<string> ins(n);
	vector<vector<int>> fins;//comprimento das string q terminam ali tbm
	for(int i = 0; i < n; i++)
		cin >> ins[i];
	//sort(ins.begin(),ins.end(),[](auto lhs, auto rhs) {
	//	return lhs.size() <= rhs.size();
	//});
	sort(ins.begin(),ins.end());
	int maxi = 0;
	for(string s : ins) {
		int i = 0;
		for(int k = 0; k < s.size(); k++) {
			char c = s[k]-'a';
			if(trie[c].size() <= i || trie[c][i] == -1){
				maxi++;
				trie[c].resize(maxi+1, -1);
				trie[c][i] = maxi;
				fins.resize(maxi+1);
			}
			i = trie[c][i];
			if(tem(fins[i], k+1)){
				cout <<  "Conjunto Ruim" << endl;
				return;
			}
			if(k == s.size()-1)
				fins[i].push_back(s.size());
		}
	}
	for(auto&vec: trie)
		vec.resize(maxi+1,0);
	cout << "Conjunto Bom" << endl;
}

int main() { _
	while(1){ 
		int n;
		cin >> n;
		if(n==0)break;
		solve(n);
	}
	exit(0);
}

