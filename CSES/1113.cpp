#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { __
	string s, s2, ans;
	cin >> s;
	s2 = s;
	sort(s2.begin(),s2.end());
	vector<vector<pair<char,int>>> gr(256);
	vector<int> cnt(256);
	for(int i = 0; i < s.size(); i++) {
		gr[s2[i]].push_back({s[i],cnt[s[i]]});
		cnt[s[i]]++;
	}
	pair<char,int> p = {'#',0};
	while(ans.size() != s.size()) {
		ans.pb(p.f);
		p = gr[p.f][p.s];
	}
	reverse(ans.begin(),ans.end());
	ans.pop_back();
	cout << ans << endl;
	exit(0);
}
