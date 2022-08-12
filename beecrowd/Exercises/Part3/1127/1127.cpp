#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	while(1) {
		int m,t;
		cin >> m >> t;
		if(m == 0 and t == 0)
			break;
		string fi(m,0), sec(t,0);
		map<string,char> mapa = {{"A",0},{"A#",1},{"Bb",1},{"B",2},{"Cb",2},{"C",3},{"B#",3},{"C#",4},{"Db",4},{"D",5},{"D#",6},{"Eb",6},{"E",7},{"Fb",7},{"F",8},{"E#",8},{"F#",9},{"Gb",9},{"G",10},{"G#",11},{"Ab",11}};
		for(int i = 0; i < m; i++) {
			string st;
			cin >> st;
			fi[i] = mapa[st];
		}
		for(int i = 0; i < t; i++) {
			string st;
			cin >> st;
			sec[i] = mapa[st];
		}
		bool algumdeu = false;
		for(int r = 0; r < 12; r++) {
			for(int k = 0; k < sec.length(); k++)
				sec[k] = (sec[k] + 1)%12;
			vector<int> pi(sec.length());
			pi[0] = 0;
			for(int i = 1, j = 0; i < sec.size(); i++) {
				while(j > 0 and sec[j] != sec[i])
					j = pi[j-1];
				if(sec[j] == sec[i]) j++;
				pi[i] = j;
			}
			bool deu = false;
			for(int i = 0, j = 0; i < fi.size(); i++) {
				while(j > 0 and sec[j] != fi[i])
					j = pi[j-1];
				if(sec[j] == fi[i]) j++;
				if(j == sec.size()) {
					deu = true;
					break;
				}
			}
			if (deu){
				cout << "S" << endl;
				algumdeu = true;
				break;
			}
		}
		if(!algumdeu)
			cout << "N" << endl;
	}
	exit(0);
}

