#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 300;

int r,c,k;
bool mat[MAX][MAX];
int pref[MAX][MAX];

int main() { _
	while(1) {
		cin >> r >> c >> k;
		if (r == 0 && c == 0 && k == 0)
			break;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				char v;
				cin >> v;
				if(v == 'X'){
					mat[i][j] = false;
					if (i == 0)
						pref[i][j] = 0;
					else
						pref[i][j] = pref[i-1][j];
				}
				else {
					mat[i][j] = true;
					if (i == 0)
						pref[i][j] = 1;
					else
						pref[i][j] = pref[i-1][j]+1;
				}
			}

		int mini = INF;
		for(int i1 = 0; i1 < r; i1++)
			for(int i2 = i1; i2 < r; i2++) 
				for(int j = 0, j2 = 0, currsum = 0; j < c; j++) {
					for(; j2 < c && currsum < k; j2++)
						currsum += pref[i2][j2]-pref[i1][j2]+mat[i1][j2];
					if(currsum < k)
						break;
					mini = min(mini,(j2-j)*(i2-i1+1));
					currsum -= pref[i2][j]-pref[i1][j]+mat[i1][j];
				}
		cout << mini << endl;
	}
	exit(0);
}
