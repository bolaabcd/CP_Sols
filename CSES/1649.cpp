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
const int MAX = 2e5+10;

int seg[4*MAX];

int n,q;
void update(int i, int v, int p = 1, int l = 0, int r = n-1) {
	if(l > i or r < i)
		return;
	if(l == r) {
		seg[p] = v;
		return;
	}
	int mid = (l+r)/2;
	update(i,v,2*p,l,mid);
	update(i,v,2*p+1,mid+1,r);
	seg[p] = min(seg[2*p],seg[2*p+1]);
}

int query(int a, int b, int p = 1, int l = 0, int r = n-1) {
	if(l > b or r < a)
		return INF;
	if(a <= l and r <= b)
		return seg[p];
	int mid = (l+r)/2;
	return min(query(a,b,2*p,l,mid),query(a,b,2*p+1,mid+1,r));
}

int main() { __
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		update(i,x);
	}

	for(int i = 0; i < q; i++) {
		int t,a,b;
		cin >> t >> a >> b;
		if(t == 1) {
			a--;
			update(a,b);
		} else {
			a--;
			b--;
			cout << query(a,b) << endl;
		}
	}

	exit(0);
}
