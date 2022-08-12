#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int as[212345];
pair<int, int> t[4*212345];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, min(r, tm)), 
                   get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

int main() { _
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> as[i];
	build(as,1,0,m-1);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int xi, yi, xf, yf, k;
		//cin >> xi >> yi >> xf >> yf >> k;
		cin >> yi >> xi >> yf >> xf >> k;
		int dx = abs(xf-xi), dy = abs(yf-yi);
		if(dx%k || dy%k || as[xi-1] >= yi || as[xf-1] >= yf) {
			//cout << dx%k << ' ' << dy%k << ' ' << (as[xi-1] >= yi) << ' ' << (as[xf-1] >= yf) << endl;;
			cout << "No" << endl;
			continue;
		}
		int ma = yi + k*((n-yi)/k);
		if(xi > xf)
			swap(xi,xf);
		// starts in valid position, ends in valid position, and if it werent for the obstacles, could do it.
		//cout << get_max(1,0,m-1,xi-1,xf-1).first << endl;
		//cout << ma << endl;
		if(get_max(1,0,m-1,xi-1, xf-1).first < ma)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	exit(0);
}
