#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXI = 5e3+10;

int res[MAXI][MAXI];

int main() { _
	string s;
	cin >> s;
	vector<int> vec(s.size()+1,0);
	for(int i = 0; i < s.size(); i++) {
		res[i][i] = 1;
		vec[1]++;
		if(i+1 < s.size() &&s[i] == s[i+1]) res[i][i+1] = 2, vec[2]++; 
	}
	for(int i = 3; i <= s.size(); i++) {
		for(int j = 0; j <= s.size()-i; j++) {
			res[j][j+i-1] = (s[j] == s[j+i-1]) && res[j+1][j+i-2]; 
			if(res[j][j+i-1])
				res[j][j+i-1] = res[j][j+i/2-1]+1;

			vec[res[j][j+i-1]]++;
		}
	}
	
	for(int i = int(vec.size())-1; i>= 1; i--) vec[i-1]+=vec[i];

	for(int i = 1; i < vec.size(); i++) cout << vec[i] << " ";
	cout << endl;
	
	exit(0);
}
