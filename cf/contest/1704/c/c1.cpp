#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	cout << int(1e9) << ' ' << int(1e5) << endl;
	int sum = 0;
	for(int i = 0; i < 1e5; i++) {
		cout << sum << endl;;
		sum += 1e9/1e5;
	}
	exit(0);
}
