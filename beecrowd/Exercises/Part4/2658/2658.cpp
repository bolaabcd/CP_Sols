#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast")//Comment optimisations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5;

vector<int> null(10,0); // ultimo elemento eh o quanto somar
vector<vector<int>> seg(4*MAX+100,null);
int n,q;

int getf(vector<int>& vec) {
	int maxi = *max_element(vec.begin(),vec.begin()+9);
	//cout << "Ma: " << maxi << ' ' << vec[9] << ' ' << vec[1] << ' ' << vec[8] << ' ' << vec[7] << endl;
	for(int i = 8; i >= 0; i--)
		if(vec[i] == maxi)
			return (i+vec[9])%9;
	assert(false);
	return -1;
}

void merge(int pos, vector<int>& l, vector<int>& r, vector<int>& ans) {
	for(int i = 0; i < 9; i++)
		ans[i] = l[(i-l[9]+9)%9] + r[(i-r[9]+9)%9];
	/*cout << '-' << pos << '-' << endl;
	for(int i = 0; i < 10; i++)
		cout << l[i] << '-';
	cout << endl;
	for(int i = 0; i < 10; i++)
		cout << r[i] << '-';
	cout << endl;
	for(int i = 0; i < 10; i++)
		cout << ans[i] << '-';
	cout << endl;*/
	//return ans;
}

void prop(int pos, int in, int fin) {
	//auto cop = seg[pos];
	int amt = seg[pos][9]%9;
	if (amt == 3) {
		int prev = seg[pos][0];
		seg[pos][0] = seg[pos][6];
		seg[pos][6] = seg[pos][3];
		seg[pos][3] = prev;
		prev = seg[pos][1];
		seg[pos][1] = seg[pos][7];
		seg[pos][7] = seg[pos][4];
		seg[pos][4] = prev;
		prev = seg[pos][2];
		seg[pos][2] = seg[pos][8];
		seg[pos][8] = seg[pos][5];
		seg[pos][5] = prev;
	} else if (amt != 0) {
		int prev = seg[pos][0];
		for (int i = 0; i < 8; i++) {
			seg[pos][0] = seg[pos][(9-amt)%9];
			amt = (9-amt)%9;
		}
		seg[pos][amt] = prev;
	} 
	seg[2*pos+1][9] = (seg[2*pos+1][9]+amt+9)%9;
	seg[2*pos][9] = (seg[2*pos][9]+amt+9)%9;
	seg[pos][9] = 0;
}

void upd(int pos, int in, int fin, int l, int r, int sum) {
	//cout << "UVA: " << pos << ' ' << in << ' ' << fin << ' ' << l << ' ' << r << ' ' << sum << endl;
	if (r < in or l > fin)
		return;
	if (l <= in and fin <= r) {
		seg[pos][9] = (seg[pos][9] + sum + 9)%9;
		return;
	}
	int mid = (in+fin)/2;
	prop(pos, in, fin);
	upd(2*pos, in, mid, l, r, sum);
	upd(2*pos+1, mid+1, fin, l, r, sum);
	merge(pos, seg[2*pos], seg[2*pos+1],seg[pos]);
}

void querry_merger(int pos, int in, int fin, int l, int r, vector<int>& ans) {
	if (r < in or l > fin)
		return;
	if (l <= in and fin <= r) {
		for (int i = 0; i < 9; i++) {
			ans[i] += seg[pos][(i-seg[pos][9]+9)%9];
		}
		return;
	}
	int mid = (in + fin)/2;
	prop(pos, in, fin);
	querry_merger(2*pos,in,mid,l,r,ans);
	querry_merger(2*pos+1,mid+1,fin,l,r,ans);
}

void getv(int pos, int in, int fin) {
	//for(int i = 0; i < 9; i++)
	//	if (vec[i] == 1)
	//		return (i+vec[9])%9;
	//assert(false);
	//return -1;
	if (fin < in)
		return;
	if (in == fin){
		for(int i = 0; i < 9; i++)
			if(seg[pos][i] == 1){
				cout << (i+seg[pos][9])%9 << endl;
				return;
			}
	}
	int mid = (in+fin)/2;
	prop(pos,in,fin);
	getv(2*pos,in,mid);
	getv(2*pos+1,mid+1,fin);
}

void setv(int pos, int in, int fin) { // seta tudo pra 1
	if (fin < in)
		return;
	if (in == fin){
		seg[pos][1] = 1;
		return;
	}
	int mid = (in+fin)/2;
	setv(2*pos,in,mid);
	setv(2*pos+1,mid+1,fin);
	merge(pos,seg[2*pos], seg[2*pos+1], seg[pos]);
}

int main() { _
	cin >> n >> q;
	//for(int i = 0; i < n; i++)
	setv(1,0,n-1);
	//upd(1,0,n-1,0,n-1,1);
	for(int i = 0; i < q; i++) {
		int a,b;
		cin >> a >> b;
		auto ans = null;
		querry_merger(1, 0, n-1, a, b, ans);
		int f = getf(ans); 
		//cout <<"F: " <<  f << endl;
		upd(1, 0, n-1, a, b, f);
		/*for(int i = 0; i < 10; i++)
			cout << seg[1][i] << '_';
			cout << endl;*/
	}
	//for(int i = 0; i < n; i++)
	//	cout << getv(querry(1, 0, n-1, i, i)) << endl;
	getv(1,0,n-1);
	exit(0);
}

