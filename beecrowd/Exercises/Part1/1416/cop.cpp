#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int defpenality(pair<int,int> FaTime) {
	if(FaTime.second == 0)
		return 0;
	return FaTime.second+20*FaTime.first;
}

int main() { _
	while(1) {
		int t, p;
		cin >> t >> p;
		if(t == 0 && p == 0)
			break;
		assert(cin.peek() == '\n');
		cin.get();
		// team -> {problem -> {FAs, time}, teamnumber}
		vector<pair<vector<pair<int,int>>,int>> teams(t,{vector<pair<int,int>>(p),0}); // -1
		// team -> number of solved problems
		vector<int> teamnosps(t,0);
		// team -> total default penality
		vector<int> teamtp(t,0);
		for(int i = 0; i < t; i++) {
			teams[i].second = i;
			for(int j = 0; j < p; j++) {
				cin >> teams[i].first[j].first;
				assert(cin.peek() == '/');
				cin.get();
				if(cin.peek() == '-'){
					cin.get();
					teams[i].first[j].second = 0; // -1
				}
				else{
					teamnosps[i]++;
					cin >> teams[i].first[j].second;
					teamtp[i] += defpenality(teams[i].first[j]);
				}
			}
		}
		sort(teams.begin(), teams.end(),[&](auto &l, auto& r) {
			int ln = l.second, rn = r.second;
			if(teamnosps[ln] != teamnosps[rn])
				return teamnosps[ln] > teamnosps[rn];
			return teamtp[ln] < teamtp[rn];
		});
		int maxiu = INF, maxid = 19;
		for(int k = 1; k < t; k++) {
			int i = teams[k].second, iminus = teams[k-1].second;
			if(teamnosps[iminus] > teamnosps[i])
				continue;
			assert(teamnosps[iminus] == teamnosps[i]);
			assert(teamtp[iminus] <= teamtp[i]);
			int sumTa_Tb = 0,sumFb_Fa = 0;
			for(int j = 0; j < p; j++) {
					sumTa_Tb += teams[k].first[j].second - teams[k-1].first[j].second;
				if(teams[k].first[j].second > 0) {
					sumFb_Fa -= teams[k].first[j].first;
				}
				if( teams[k-1].first[j].second > 0) {
					sumFb_Fa += teams[k-1].first[j].first;
				}
			}
			int D = sumTa_Tb-20*sumFb_Fa;
			// int D = teamtp[i] - teamtp[iminus];
			assert(D>=0);
			assert(D == teamtp[i] - teamtp[iminus]);
			if(sumFb_Fa == 0)
				continue;
			if(D == 0){
				maxid = 0;
				maxiu = 0;
				break;
			}
			
			if(sumFb_Fa < 0){
				if(D % (-1*sumFb_Fa) == 0)
					maxid = min(maxid, -D/sumFb_Fa-1);
				else
					maxid = min(maxid, -D/sumFb_Fa);					
			// 	maxid = min(maxid, 20-sumTa_Tb/sumFb_Fa);
				assert(maxid >= 0);
			}
			else {
				if(D % sumFb_Fa == 0)
					maxiu = min(maxiu, D/sumFb_Fa-1);
				else
					maxiu = min(maxiu, D/sumFb_Fa);
			// 	maxiu = min(maxiu, sumTa_Tb/sumFb_Fa-20);
				assert(maxiu >= 0);
				
			}
		}
		assert(20 - maxid >= 0);
		if(20-maxid == 19 && maxiu == 40) {
			cerr << t << " " << p << endl;
			// for(int i = 0; i < t; i++){
			// 	for(int j = 0; j < p; j++) {
			// 		cerr <<  << endl;
			// 	}
			// }
			assert(false);
		}
		cout << 20 - maxid << " ";
		if(maxiu == INF)
			cout << "*";
		else
			cout << 20 + maxiu;
		cout << endl;
	}
	exit(0);
}
