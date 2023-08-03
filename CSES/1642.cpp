#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int a[1123+10];
tuple<int,int,int> vals[1123456+10];

int main() { __
	int n, x;
	cin >> n >> x;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int siz = (n*(n-1))/2;
	int k = 0;
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++) {
			get<0>(vals[k]) = a[i]+a[j];
			get<1>(vals[k]) = i;
			get<2>(vals[k]) = j;
			k++;
		}
	sort(vals,vals+siz);
	for(int i = 0; i < siz; i++)  {
		int x2 = x - get<0>(vals[i]);
		int l = 0, r = siz-1;
		while(l < r) {
			int mid = (l+r)/2;
			if(get<0>(vals[mid]) >= x2)
				r = mid;
			else
				l = mid+1;
		}

		if(l == r and get<0>(vals[l]) == x2) {
			int lb = l;
			l = 0, r = siz-1;
			while(l < r) {
				int mid = (l+r+1)/2;
				if(get<0>(vals[mid]) <= x2)
					l = mid;
				else
					r = mid-1;
			}
			if(l == r and get<0>(vals[l]) == x2) {
				int ub = l;
				for(int kk = lb; kk <= ub; kk++) {
					set<int> comps;
					comps.insert(get<1>(vals[i]));
					comps.insert(get<2>(vals[i]));
					comps.insert(get<1>(vals[kk]));
					comps.insert(get<2>(vals[kk]));
					if(comps.size() == 4) {
						cout << get<1>(vals[i])+1 << ' ';
						cout << get<2>(vals[i])+1 << ' ';
						cout << get<1>(vals[kk])+1 << ' ';
						cout << get<2>(vals[kk])+1 << endl;
						exit(0);
					}
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	exit(0);	
}
