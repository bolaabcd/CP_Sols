#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void get_and_print(int amt) {
	string s;
	cin >> s;
	amt--;

	string out;
	int i;
	for(i = 0; i < s.size() && s[i] == '0'; i++) {
		out += "0 ";
		amt--;
	}
	assert(amt >= 0);

	string revout;
	int j;
	bool first = true;
	for(j = s.size()-1; j > i && amt > 0; j--) {
		if(first){
			revout.push_back(s[j]);
			first = false;
		}
		revout.push_back(' ');
		revout.push_vack(s[j-1]);
	}
	reverse(revout.begin(), revout.end());

	cout << out;
	assert(i <= j);
	for(int k = i; k <= j; k++) {
		cout << k;
	}

	assert(amt == 0);
	assert(cin.peek() == '\n')
	cin.get();
}

int main() { _
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << 'P';
		int pos;
		for(int i = 1; i < s.size(); i++) {
			if(s[i] == 'P' || s[i] == 'T')
				cout << ' ';
			if(s[i] == 'P')
				pos = i+1;
			cout << s[i];
		}
		cout << endl;

		string num;
		for(int i = pos; i < s.size() && s[i] >= '0' && s[i] <= '9'; i++)
			num.push_back(s[i]);
		int amt = atoi(num.c_str());

		assert(cin.peek() == '\n');
		cin.get();
		while(cin.peek() != 'T') {
			while(cin.peek() < '0' || cin.peek() > '9'){
				char c;
				cin >> c;
				cout << c;
			}
			cout << ' ';
			get_and_print(amt);
			cout << endl;
		}

		char t,p;
		cin >> t >> p;
		assert(t == 'T' && p == 'P');
		cout << "TP ";
		get_and_print(amt);
		cout << endl;
	}
	exit(0);
}
