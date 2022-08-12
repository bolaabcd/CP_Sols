#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10;

int l,k;
int x[MAX];
int trythis(int m, int n) {
	if(n%l != 0)
		return INF;
	sort(x,x+k);
	int tot = n/l,amt = 0, i = 0, j = k, aux = 1;

	while(tot > 0) {
		if(i >= j)
			return INF;
		if(-x[i] - x[j] == m) {
			amt += aux;
			i++;
			j-=aux-1;
			tot--;
		} else if (-x[i] - x[j] > m) {
			i++;
		} else if (-x[i] - x[j] < m) {
			j--;
			aux = 2;
		}
	}
	return amt;
}

int main() { _
	while(1) {
		int n,m;
		cin >> n >> m >> l >> k;
		n*=100;
		m*=100;
		if(m == n && n == 0)
			break;
		for(int i = 0; i < k; i++) cin >> x[i], x[i] = -x[i], x[i] *= 100;

		x[k] = 0;
		int ans = min(trythis(n,m),trythis(m,n));
		if(ans == INF)
			cout << "impossivel" << endl;
		else
			cout << ans << endl;
	}
	exit(0);
}
