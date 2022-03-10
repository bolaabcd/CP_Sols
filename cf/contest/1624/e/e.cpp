#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define LIM 10
typedef long long ll;
// i, l, r, filho
typedef pair<tuple<int,int,int>,int> resp;
const resp rfalse = {{0,-1,-1},-1};
const resp rundef = {{-1,-1,-1},-1};

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
vector<vector<vector<resp>>> trios;
vector<vector<resp>> duplas;
// map<tuple<char,char,char>,resp> trios;
// map<pair<char,char>,resp> duplas;

int n, m;
vector<resp> dp;
string s;

resp rec(int i){
	if (i <= 0)
		return dp[i] = rfalse;
	if (get<0>(dp[i].first) != -1)
		return dp[i];
	resp dois = i >= 1 ? duplas[s[i-1]-'0'][s[i]  -'0']           : rfalse;
	resp tres = i >= 2 ? trios [s[i-2]-'0'][s[i-1]-'0'][s[i]-'0'] : rfalse;

	if (i == 1)
		return dp[i] = dois;
	else if (i == 2)
		return dp[i] = tres;
	else if (get<0>(tres.first) && get<0>(rec(i-3).first))
		return dp[i] = {tres.first,i-3};
	else if (get<0>(dois.first) && get<0>(rec(i-2).first))
		return dp[i] = {dois.first,i-2};
	else
		return dp[i] = rfalse;
}

vector<tuple<int,int,int>> ans;

void vetorizar(int i) {
	assert((i >=0 && i <= m-1) || i == -2);
	if(i == -2)
		return;
	vetorizar(dp[i].second);
	ans.push_back({get<1>(dp[i].first), get<2>(dp[i].first), get<0>(dp[i].first)});
}

int main() { _
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		ans = vector<tuple<int,int,int>>();
		dp = vector<resp> (m,rundef);
		duplas = vector<vector<resp>>(LIM,vector<resp>(LIM,rfalse));
		trios  = vector<vector<vector<resp>>>(LIM,vector<vector<resp>>(LIM,vector<resp>(LIM,rfalse)));
		for(int i = 0; i < n; i++) {
			string t;
			cin >> t;
			for(int j = 0; j + 1 < t.size(); j++) {
				duplas[t[j]-'0'][t[j+1]-'0'] = {{i + 1,j+1,j+1+1},-2};
				if(j+2 < t.size()) {
					trios[t[j]-'0'][t[j+1]-'0'][t[j+2]-'0'] = {{i + 1, j+1, j+2+1}, -2};
				} 
			}
		}
		cin >> s;
		
		if(get<0>(rec(m-1).first)){
			vetorizar(m-1);
			cout << ans.size() << endl;
			for(auto [a,b,c] : ans)
				cout << a << " " << b << " " << c << endl;
		}
		else
			cout << -1 << endl;
	}
	
	return 0;
}
