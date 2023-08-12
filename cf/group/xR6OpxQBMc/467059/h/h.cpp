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

int main() { __
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++) {
			int x;
			cin >> x;
			if(x) {
				cout << abs(i-2) + abs(j-2) << endl;
				exit(0);
			}
		}
	
	exit(0);
}
