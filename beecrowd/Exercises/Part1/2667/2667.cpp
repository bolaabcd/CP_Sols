#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	string s;
	cin >> s;
	char sum = 0;
	for(char c : s)
		sum = (sum + c-'0')%3;

	cout << (char)(sum+'0') << endl;

	exit(0);
}
