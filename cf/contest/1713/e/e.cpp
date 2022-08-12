#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e3+10;
int arr[MAX][MAX];

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> arr[i][j];
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			if(i == j)
				cout << arr[i][j] << ' ';
			else if (i < j)
				cout << min(arr[i][j],arr[j][i]) << ' ';
			else
				cout << max(arr[i][j],arr[j][i]) << ' ';
		cout << endl;
	}
}

int main() { _
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
