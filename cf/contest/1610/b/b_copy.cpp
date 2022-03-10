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
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		set<int> diffs;
		for(int& el:a) cin >> el,diffs.insert(el);

		if(diffs.size() <= 2) {
			cout << "YES" << endl;
			continue;
		}

		vector<int> antes(n+1,0),depois(n+1,0);
		for(int i = n-1; i>=0; i--) {
			depois[a[i]]++;
		}
		int amteq = 0;
		bool foi = false;
		for(int i = 0; i < n; i++) {
			if(amteq >= diffs.size()-1) {
				foi = true;
				break;
			}
			if(depois[a[i]] == antes[a[i]]){
				amteq--;
			}
			antes[a[i]]++;
			depois[a[i]]--;
			if(depois[a[i]] == antes[a[i]])
				amteq++;
			// cout << a[i] << " eq "<< amteq << endl;
			// cout << antes[a[i]] << " " << depois[a[i]] << endl;
			
			if(amteq >= diffs.size()-1) {
				foi = true;
				break;
			}
		}


		vector<int> antes2(n+1,0),depois2(n+1,0);
		for(int i = n-1; i>=1; i--) {
			depois2[a[i]]++;
		}
		amteq = 0;
		if(!foi)
		for(int i = 1; i < n; i++) {
			if(amteq >= diffs.size()-2) {
				foi = true;
				break;
			}
			if(depois2[a[i]] == antes2[a[i]]){
				amteq--;
			}
			antes2[a[i-1]]++;
			depois2[a[i]]--;
			if(depois2[a[i-1]] == antes2[a[i-1]])
				amteq++;
			// cout << a[i] << " eq "<< amteq << endl;
			// cout << antes2[a[i-1]] << " " << depois2[a[i]] << endl;
			if(amteq >= diffs.size()-2) {
				foi = true;
				break;
			}
		}




		if(foi)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	exit(0);
}

/*
3
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