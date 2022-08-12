#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
ll as[112345], dir[112345], esq[112345];
int main() { _
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> as[i];
	dir[0] = 0;
	for(int i = 1; i < n; i++)
		dir[i] = max(as[i-1]-as[i],0LL);
	esq[n-1] = 0;
	for(int i = n-2; i>=0; i--)
		esq[i] = max(as[i+1]-as[i],0LL);
	
	for(int i = 1; i < n; i++)
		dir[i] += dir[i-1];
	for(int i = n-2; i>=0; i--)
		esq[i] += esq[i+1];

	for(int i = 0; i < m; i++) {
		int s,t;
		cin >> s >> t;
		s--;
		t--;
		if (s < t)
			cout << dir[t]-dir[s] << endl;
		else
			cout << esq[t]-esq[s] << endl;
	}
	exit(0);
}
