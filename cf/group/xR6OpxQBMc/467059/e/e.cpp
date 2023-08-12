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

int arr[1000+100];

int main() { __
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x]++;
	}
	for(int i = 0; i < 1000+10; i++)
		if(arr[i] > (n+1)/2) {
			cout << "NO" << endl;
			exit(0);
		}
	cout << "YES" << endl;
	exit(0);
}
