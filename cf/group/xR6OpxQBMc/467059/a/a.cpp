#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


	int amts[2];
int main() { __
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if(c == 'L')amts[0]++;
		else
			amts[1]++;
	}
	cout << amts[0]+amts[1]+1;
	exit(0);
}
