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

int arr[20][200000];

int main() { __
	int n,q;
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> arr[0][i];
	for(int i = 1; (1<<i) <= n; i++)
		for(int j = 0; j <= n-(1<<i); j++)
			arr[i][j] = min(arr[i-1][j],arr[i-1][j+(1<<(i-1))]);
	for(int i = 0; i < q; i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		if(a == b) {
			cout << arr[0][a] << endl;
			continue;
		}
		int k = 31-__builtin_clz((b-a+1));
		cout << min(arr[k][a],arr[k][b-(1<<k)+1]) << endl;
	}
	exit(0);
}
