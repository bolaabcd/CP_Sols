#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool palin(vector<int> &a, int ind) {
	if(ind == -1)
		return true;
	int n = a.size();
	for(int i = 0, j = n-1; i < n && j>=0;i++, j--) {
		while(i < n && a[i] == a[ind]){
			i++;
		}
		while(j >=0 && a[j] == a[ind]){
			j--;
		}
		if(a[i] != a[j]) {
			return false;
		}
	}
	return true;
}

int main() { _
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int& el:a) cin >> el;


		int it=-1, jt=-1;
		for(int i = 0; i < n; i++) {
			int j = n-i-1;
			if(a[i] != a[j]) {
				it = i;
				jt = j;
			}
		}
		
		if(palin(a,it) || palin(a,jt)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	exit(0);
}

/*
4
4
1 2 3 1
7
1 3 2 3 2 3 1
7
1 3 2 3 3 3 1
6
1 2 3 1 2 3


YES
YES
YES
NO


8
5
1 2 3 2 1
4
1 2 2 1
10
1 8 2 8 3 8 2 8 1 8
9 
8 1 8 2 8 2 8 1 8
10
8 1 8 2 8 2 8 1 8 1
10
8 1 8 2 8 2 8 1 8 2
10
8 1 8 2 8 2 8 1 3 3
7
1 7 2 2 1 3 3

YES
YES
YES
YES
YES
YES
NO
NO
*/