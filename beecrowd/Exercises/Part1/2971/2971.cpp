#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n, k;
	cin >> n >> k;
	k--;
	map<char,int> vals;
	vals['A'] = 0;
	for(char c = '2'; c <= '9'; c++)
		vals[c] = c-'0'-1;
	vals['D'] = 9;
	vals['Q'] = 10;
	vals['J'] = 11;
	vals['K'] = 12;

	// each player has a set of cards. Each card has it's ammount and value
	vector<set<pair<int,int>>> jogs(n);
	vector<vector<int>> jogscardsamts(n,vector<int>(13,0));
	vector<int> ncards(n,4);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 4; j++) {
			char c;
			cin >> c;
			assert(c == 'A' || c == 'D' || c == 'Q' || c == 'J' || c == 'K' || (c >= '2' && c <= '9'));
			jogscardsamts[i][vals[c]]++;
		}
		for(int j = 0; j < 13; j++){
			assert(jogscardsamts[i][j] >= 0);
			if(jogscardsamts[i][j] > 0)
				jogs[i].insert({jogscardsamts[i][j],j});
		}
	}

	int joker = k, currentplayer = k;
	ncards[joker]++;
	for(int i = 0; i < n; i++) {
		if(jogs[i].size() == 1 && joker != i){
			assert(ncards[i] == 4);
			cout << i + 1 << endl;
			exit(0);
		}
	}
	bool jokercanmove = false;
	while(1) {
		assert(ncards[currentplayer] == 5);
		if (currentplayer == joker && jokercanmove){
			joker = (joker+1)%n;
			jokercanmove = false;
		} else {
			jokercanmove = true;
			// amt, value
			auto p = *jogs[currentplayer].begin();
			assert(p.first == jogscardsamts[currentplayer][p.second]);
			assert(p.first > 0);
			jogs[currentplayer].erase(jogs[currentplayer].begin());
			if(p.first - 1 > 0)
				jogs[currentplayer].insert({p.first-1,p.second});
			jogs[(currentplayer+1)%n].erase({jogscardsamts[(currentplayer+1)%n][p.second],p.second});
			jogs[(currentplayer+1)%n].insert({jogscardsamts[(currentplayer+1)%n][p.second]+1,p.second});
			jogscardsamts[currentplayer][p.second]--;
			jogscardsamts[(currentplayer+1)%n][p.second]++;
			assert(jogscardsamts[(currentplayer+1)%n][p.second] > 0);
		}
		ncards[currentplayer]--;
		ncards[(currentplayer+1)%n]++;
		if(jogs[currentplayer].size() == 1 && joker != currentplayer){
			assert(ncards[currentplayer] == 4);
			cout << currentplayer + 1 << endl;
			exit(0);
		}
		currentplayer = (currentplayer+1)%n;
		if(jogs[currentplayer].size() == 1 && joker != currentplayer){
			assert(ncards[currentplayer] == 4);
			cout << currentplayer + 1 << endl;
			exit(0);
		}
	}

	exit(1);
}
