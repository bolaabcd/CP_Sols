#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string pre,in;
bool down(char from, char to) {
	for(char c: pre) {
		if(c == from)
			return true;
		else if (c == to)
			return false;
	}
	assert(false);
	return false;
}

int main() { _
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		cin >> pre >> in;
		stack<char> parents;

		cout << in[0];
		char prev = in[0];
		for(int i = 1; i < n; i++) {
			if(down(prev,in[i]))
				cout << in[i];				
			else if (!parents.empty() && down(in[i],parents.top())) {
				cout << parents.top();
				parents.pop();
				parents.push(in[i]);
			} else {
				parents.push(in[i]);
			}
			prev = in[i];
		}

		while(!parents.empty()){
			cout << parents.top();
			parents.pop();
		}

		cout << endl;
	}
	exit(0);
}
