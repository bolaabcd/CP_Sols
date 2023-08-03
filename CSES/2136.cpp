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
const int MAX = 2e4+10;

int arr[MAX];

int main() { __
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < k; j++) {
			char c;
			cin >> c;
			if(c == '1')
				arr[i] |= (1 << j);
		}
	int mini = INF;
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			mini = min(mini,__builtin_popcount(arr[i]^arr[j]));
	cout << mini << endl;
	exit(0);
}
