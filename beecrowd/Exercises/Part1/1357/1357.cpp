#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void writeval(char c, vector<vector<char>> &vec, int pos) {
	int p = pos*3;
	assert(p >= 0 && p+1 < vec[0].size());
	if(c == '9'||c == '0')
		vec[0][p] = '.';
	else
		vec[0][p] = '*';

	if(c == '1'||c == '3' || c =='4' || c == '5')
		vec[1][p] = '.';
	else
		vec[1][p] = '*';

	if(true)
		vec[2][p] = '.';
	else
		vec[2][p] = '*';

	if(c == '1'||c == '2' || c =='5' || c == '8')
		vec[0][p+1] = '.';
	else
		vec[0][p+1] = '*';

	if(c == '1'||c == '2' || c =='3' || c == '6' || c == '9')
		vec[1][p+1] = '.';
	else
		vec[1][p+1] = '*';

	if(true)
		vec[2][p+1] = '.';
	else
		vec[2][p+1] = '*';
}

char readval(vector<vector<char>> &vec, int pos) {
	int tposi = 3*pos;
	assert(tposi >= 0 && tposi+1 < vec[0].size());
	assert(vec[2][tposi] == '.' && vec[2][tposi+1] == '.');

	if(vec[0][tposi] == '*' && vec[1][tposi] == '.' && vec[0][tposi+1] == '.' && vec[1][tposi+1] == '.')
		return '1';
	if(vec[0][tposi] == '*' && vec[1][tposi] == '*' && vec[0][tposi+1] == '.' && vec[1][tposi+1] == '.')
		return '2';
	if(vec[0][tposi] == '*' && vec[1][tposi] == '.' && vec[0][tposi+1] == '*' && vec[1][tposi+1] == '.')
		return '3';
	if(vec[0][tposi] == '*' && vec[1][tposi] == '.' && vec[0][tposi+1] == '*' && vec[1][tposi+1] == '*')
		return '4';
	if(vec[0][tposi] == '*' && vec[1][tposi] == '.' && vec[0][tposi+1] == '.' && vec[1][tposi+1] == '*')
		return '5';
	if(vec[0][tposi] == '*' && vec[1][tposi] == '*' && vec[0][tposi+1] == '*' && vec[1][tposi+1] == '.')
		return '6';
	if(vec[0][tposi] == '*' && vec[1][tposi] == '*' && vec[0][tposi+1] == '*' && vec[1][tposi+1] == '*')
		return '7';
	if(vec[0][tposi] == '*' && vec[1][tposi] == '*' && vec[0][tposi+1] == '.' && vec[1][tposi+1] == '*')
		return '8';
	if(vec[0][tposi] == '.' && vec[1][tposi] == '*' && vec[0][tposi+1] == '*' && vec[1][tposi+1] == '.')
		return '9';
	if(vec[0][tposi] == '.' && vec[1][tposi] == '*' && vec[0][tposi+1] == '*' && vec[1][tposi+1] == '*')
		return '0';
	assert(false);
}

int main() { _
	while(1) {
		int d;
		cin >> d;
		if(d == 0)
			break;
		char c;
		cin >> c;
		if(c == 'S'){
			string s;
			cin >> s;
			assert(s.size() == d);
			vector<vector<char>> vec (3,vector<char>(3*d-1,' '));
			for(int i = 0; i < d; i++)
				writeval(s[i],vec,i);
			for(auto &v:vec){
				for(char &ch:v)
					cout << ch;
				cout << endl;				
			}

			// cout << endl;
		} else {
			vector<vector<char>> vec (3,vector<char>(3*d-1,' '));
			// for(auto &v:vec)
			// 	for(char &ch:v)
			// 		cin >> ch;
			string empty;
			getline(cin,empty);
			assert(empty == "");
			for(int i = 0; i < 3; i++) {
				string lin;
				getline(cin,lin);
				assert(lin.size() == 3*d-1);
				for(int j = 0; j < 3*d-1; j++)
					vec[i][j] = lin[j];
			}
			for(int i = 0; i < d; i++)
				cout << readval(vec,i);
			cout << endl;
		}
	}
	exit(0);
}
