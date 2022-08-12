#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n,m;
	cin >> n >> m;
	vector<int> arr(n);
	for(int&i:arr)cin>>i;
	string s;
	for(int i = 0; i < m; i++)s.push_back('B');
	for(int i = 0; i < arr.size(); i++) {
		int mini = min(arr[i],m+1-arr[i]), maxi = max(arr[i],m+1-arr[i]);
		if(s[mini-1] != 'A') s[mini-1] = 'A';
		else s[maxi-1] = 'A';
	}
	cout << s << endl;
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
