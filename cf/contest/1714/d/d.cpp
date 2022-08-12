#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// KMP
//
// mathcing(s, t) retorna os indices das ocorrencias
// de s em t
// autKMP constroi o automato do KMP
//
// Complexidades:
// pi - O(n)
// match - O(n + m)
// construir o automato - O(|sigma|*n)
// n = |padrao| e m = |texto|

// f50359
template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

// c82524
template<typename T> vector<int> matching(T& s, T& t) {
	vector<int> p = pi(s), match;
	for (int i = 0, j = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()) match.push_back(i-j+1), j = p[j-1];
	}
	return match;
}

// 79bd9e
struct KMPaut : vector<vector<int>> {
	KMPaut(){}
	KMPaut (string& s) : vector<vector<int>>(26, vector<int>(s.size()+1)) {
		vector<int> p = pi(s);
		auto& aut = *this;
		aut[s[0]-'a'][0] = 1;
		for (char c = 0; c < 26; c++)
			for (int i = 1; i <= s.size(); i++)
				aut[c][i] = s[i]-'a' == c ? i+1 : aut[c][p[i-1]];
	}
};

bool ok(vector<bool> &b) {
	for(bool bo: b)
		if(!bo)
			return false;
	return true;
}

int amtl(int a, int b, vector<bool>&bo) {
	int tot = 0;
	for(int i = a; i <=b; i++)
		tot += !bo[i];
	return tot;
}

void solve() {
	string t;
	cin >> t;
	int n;
	cin >> n;
	vector<bool> marc(t.size(),false);
	vector<string> sis;
	vector<tuple<int,int,int>> rangs;
	vector<pair<int,int>> rs,ans;
	for(int i = 0; i < n; i++) {
		string si;
		cin >> si;
		sis.push_back(si);
	}
	int kkk = 0;
	for(int w = 0; w < sis.size(); w++) {
		string si = sis[w];
		vector<int> mat = matching(si,t);
		for(int j : mat) {
			for(int k = 0; k < si.size(); k++)
				marc[j+k] = true;
			rangs.push_back({j,j+si.size()-1,kkk++});
			rs.push_back({w+1,j+1});
		}
	}
	for(int i = 0; i < t.size(); i++)
		if (!marc[i]) {
			cout << -1 << endl;
			return;
		}
	
	sort(rangs.begin(),rangs.end());
	// pega oq cobre mais novos
	vector<bool> m2(t.size(),false);
	while(!ok(m2)) {
		int maxii, maxi = -INF;
		for(int i = 0; i < rangs.size(); i++) {
			int a = get<0>(rangs[i]),b = get<1>(rangs[i]);
			if(amtl(a,b,m2) > maxi) {
				maxi = amtl(a,b,m2);
				maxii = i;
			}
		}
		ans.push_back(rs[get<2>(rangs[maxii])]);
		for(int i = get<0>(rangs[maxii]); i <= get<1>(rangs[maxii]); i++) {
			m2[i] = true;
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << endl;
	

}

int main() { _
	int qq;
	cin >> qq;
	while(qq--)solve();
	exit(0);
}
