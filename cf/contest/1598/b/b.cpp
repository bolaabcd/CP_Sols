#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

void debug_out(string s, int line) { cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t) {
    if (s[0] != ',') cerr << "Line(" << line << ") ";
    do { cerr << s[0]; s = s.substr(1);
    } while (s.size() and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}
#ifdef DEBUG
#define debug(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
#define debug(...)
#endif

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
bool deu = false;
int main() { _
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<vector<int>> dispAnd (5,vector<int>(5,0));
		vector<vector<int>> dispOr (5,vector<int>(5,0));
		vector<int> disp(5,0);
		for(int i = 0; i < n ; i++) {
			vector<bool> disps(5,false);
			for(int j = 0; j < 5; j++) {
				int v;
				cin >> v;
				if (v) {
					disp[j]++;	
					disps[j] = true;
				}
			}
			for(int j =0; j<5; j++)
			for(int k = j+1; k < 5; k++) {
				// debug(disps[i],disps[k], disps[i] || disps[k]);
				if (disps[j] && disps[k]) {
					dispAnd[j][k]++;
				}
				if (disps[j] || disps[k]) {
					dispOr[j][k]++;
					//debug(i,k);
				}
			}




		}
		deu = false;
		for(int i = 0; i < 5; i++) {
			for(int j = i+1; j < 5; j++) {
				//debug(i,j,dispAnd[i][j],dispOr[i][j]);
				if (dispOr[i][j] >= n && disp[i]-dispAnd[i][j] <= n/2 && disp[j]-dispAnd[i][j] <= n/2){
					deu = true;
					break;
				}
			}
		}

		if (deu)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	exit(0);
}


/*
1

*/