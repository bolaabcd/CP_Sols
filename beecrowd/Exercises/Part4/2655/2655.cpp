#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5;

int n,q,m;
ll seg[4*MAX+100];

ll querry(int pos, int in, int fin, int l, int r) {
	if (r < in or l > fin)
		return 0;
	if (in >= l and fin <= r)
		return seg[pos];
	int mid = (in + fin) / 2;
	return querry(2*pos, in, mid, l, r) | querry(2*pos+1, mid+1, fin, l, r);
}

void update(int pos, int in, int fin, int x, int val) {
	//cout << x << ' ' << in << ' ' << fin << endl;
	if (x < in or x > fin)
		return;
	if (x == in and x == fin) {
		seg[pos] = 1LL << val;
	//	cout << pos <<' ' <<  val << ' ' << seg[pos] << endl;
		return;
	}
	int mid = (in + fin) / 2;
	if (x <= mid)
		update(2*pos, in, mid, x, val);
	else
		update(2*pos + 1, mid + 1, fin, x, val);
	seg[pos] = seg[2*pos] | seg[2*pos + 1];
	//cout << pos << ' ' << seg[pos] << endl;
}

int main() { _
	cin >> n >> q >> m;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		update(1, 0, n - 1, i, val);
	}
	//exit(0);
	for (int i = 0; i < q; i++) {
		int v, l, r;
		cin >> v >> l >> r;
		if (v == 1)
			cout <<__builtin_popcountll(querry(1, 0, n - 1, l - 1, r - 1)) << endl;
		else
			update(1, 0, n - 1, l-1, r);
	}
	exit(0);
}
