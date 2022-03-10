#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int t;
	cin >> t;
	while (t--)
	{
		int n,k;
		cin >> n >> k;
		vector<int> cnt(26,0);
		char c;
		for(int i = 0; i < n; i++) cin >> c, cnt[c-'a']++; 
		int pares = 0;
		int resto = 0;
		for(int i: cnt) pares += i/2, resto += i%2;
		int tot = 2*(pares/k);
		resto += 2*(pares - k*(pares/k));
		tot += min(resto/k,1);
		if(n >= k)
			tot = max(tot, 1);
		cout << tot << endl;
	}
	
	exit(0);
}
