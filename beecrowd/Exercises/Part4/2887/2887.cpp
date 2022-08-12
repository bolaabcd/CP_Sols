#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5+100;

vector<int> tree[MAX];
int amts[MAX], seg[4*MAX], pais[MAX], head[MAX], pos[MAX], laz[4*MAX];
int n, t = 0;

void dfs(int i, int p){
	amts[i] = 1;
	for(int &j : tree[i])
		if (j != p) {
			dfs(j, i);
			amts[i] += amts[j];
			pais[j] = i;
			if (amts[j] > amts[tree[i][0]])
				swap(j, tree[i][0]);
		}
}

void make_segtree(int p, int l, int r) {
	if(l >= n or r < 0)
		return;
	if (l == r) {
		seg[p] = -1;
		return;
	}
	int mid = (l+r)/2;
	make_segtree(2*p,l,mid);
	make_segtree(2*p+1,mid+1,r);
	seg[p] = seg[2*p] + seg[2*p+1];
}

void rec_hld(int i, int p) {
	pos[i] = t++;
	for (int j : tree[i])
		if (j != p) {
			head[j] = tree[i][0] == j ? head[i] : j;
			rec_hld(j, i);
		}
}

void make_hld() {
	pais[0] = -1;
	dfs(0, -1);
	make_segtree(1,0,n-1);
	head[0] = 0;
	rec_hld(0, -1);
}

void prop(int i, int nelems) {
	seg[i] += laz[i]*nelems;
	laz[2*i] += laz[i];
	laz[2*i+1] += laz[i];
	laz[i] = 0;
}

void sum(int i, int in, int fin, int l, int r, int v) {
	//cout << l << ' ' << r << ' ' << v << endl;
	if (l > fin or r < in)
		return;
	if (l <= in and fin <= r) {
		laz[i] += v;
		return;
	}
	prop(i, fin-in+1);
	int mid = (in+fin)/2;
	sum(2*i,in,mid,l,r,v);
	sum(2*i+1,mid+1,fin,l,r,v);
	seg[i] = seg[2*i] + seg[2*i+1] + laz[2*i]*(mid-in+1) + laz[2*i+1]*(fin-mid-1+1);
}

int qsum(int i, int in, int fin, int l, int r) {
	//cout << i << ' ' << in << ' ' << fin << ' ' << l << ' ' << r << endl;
	if (l > fin or r < in)
		return 0;
	if (l <= in and fin <= r)
		return seg[i] + laz[i]*(fin-in+1);
	prop(i, fin-in+1);
	int mid = (in+fin)/2;
	return qsum(2*i,in,mid,l,r)+qsum(2*i+1,mid+1,fin,l,r);
}

void hsum(int u, int v, int val) {
	if (pos[u] > pos[v])
		swap(u, v);
	if (head[u] == head[v]) {
		sum(1, 0, n-1, pos[u], pos[v], val);
		return;
	}
	sum(1,0,n-1,pos[head[v]],pos[v],val);
	hsum(u, pais[head[v]],val);
}

int hqsum(int u, int v) {
	if (pos[u] > pos[v])
		swap(u,v);
	if (head[u] == head[v]){
		//cout << u << ' ' << v << ' ' << qsum(1,0,n-1,pos[u],pos[v]) << endl;
		return qsum(1,0,n-1,pos[u],pos[v]);
	}
	//cout << u << '_' << pos[u] << ' ' << v << ' ' << pos[v] << endl;
	//cout << v << ' ' << head[v] << ' ' << pais[head[v]] << endl;
	return hqsum(u,pais[head[v]]) + qsum(1,0,n-1,pos[head[v]], pos[v]);
}

int main() { _
	int q;
	cin >> n >> q;
	//memset(amts, 0, sizeof(amts));
	//memset(seg, 0, sizeof(seg));
	//memset(laz, 0, sizeof(laz));
	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		tree[u].pb(v);
		tree[v].pb(u);
	}
	make_hld();
	//cout << head[0] << ' ' << head[1] << ' ' << head[2] << ' ' << head[3] << ' ' << head[4] << endl;
	for (int i = 0; i < q; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		//cout << pos[a] << ' ' << pos[b] << ' ' << pos[c] << ' ' << pos[d] << endl;
		//cout << hqsum(a,b) << 'x' << hqsum(c,d) << endl;
		hsum(a, b, 1);
		hsum(c, d, 1);
	
		int ab = hqsum(a, b), cd = hqsum(c,d);
		//cout << ab << '+' << cd << endl;
		assert(ab == cd);
		cout << (ab+cd)/2 << endl;

		hsum(a, b, -1);
		hsum(c, d, -1);
	}
	exit(0);
}

