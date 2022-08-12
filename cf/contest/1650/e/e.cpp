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
	// //
	// int k = 0, tot = t;
	// //
	while(t--) {
		// // 
		// k++;
		// // 
		int n,d;
		cin >> n >> d;
		// vec[minp] - vec[minp-1] eh o menor minv
		int minp = -1, minv = INF;

		vector<int> vec(n);// 1-based
		for(int i = 0; i < n; i++) {
			cin >> vec[i];
			if(i == 0){
				minv = vec[i]-1;
				minp = i;
			}
			else if (vec[i] - vec[i-1]-1 < minv){
				minv = vec[i] - vec[i-1]-1;
				minp = i;
			}
		}

		// //
		// if(tot == 10000){
		// 	if(k == 140) {
		// 		cout << n << " " << d << endl;
		// 		for(int l:vec) cout << l << " ";
		// 		cout << endl;
		// 	} else {
		// 		continue;
		// 	}
		// }
		// //

		assert(minv != INF);
		assert(minp != -1);

		int maxans = minv;

		for(int m = max(minp-1,0); m <= minp; m++) {
			auto copia = vec;
			int m2 = m, n2 = n, maxv = -INF, maxp = -1;
			for(int i = 0; i < n2; i++) {
				if(i == m2)
					copia.erase(copia.begin()+i), i--, m2 = -1, n2--;
				else if (i == 0 and (copia[i]-1-1)/2 > maxv){
					maxv = (copia[i]-1-1)/2;
					maxp = copia[i]/2;
				}
				else if ((copia[i]-copia[i-1]-1-1)/2 > maxv){
					maxv = (copia[i]-copia[i-1]-1-1)/2;
					maxp = copia[i-1] + (copia[i]-copia[i-1])/2;
				}
			}
			assert(maxp != -1);
			if(d-copia[n2-1]-1 > maxv) {
				maxv = d-copia[n2-1]-1;
				maxp = d;
			}
			if(maxv == 0)
				continue;
			copia.push_back(maxp);
			sort(copia.begin(), copia.end());

			int nmin = INF;
			for(int i = 0; i < n; i++) {
				if(i == 0)
					nmin = min(nmin,copia[i]-1);
				else{
					nmin = min(nmin,copia[i] - copia[i-1]-1);
				}
			}
			maxans = max(maxans,nmin);
		}

		cout << maxans << endl; 
	}
	exit(0);
}


/*
1
2 5
1 5

1




9

3 12
3 5 9

2 5
1 5

2 100
1 2

5 15
3 6 9 12 15

3 1000000000
1 400000000 500000000

2 10
3 4

2 2
1 2

4 15
6 11 12 13

2 20
17 20

*/