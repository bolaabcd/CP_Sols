#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n;
	cin >> n;
	vector<int> aind(n);
	vector<int> nmatchs(n,0);
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		aind[val-1] = i;
	}
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		nmatchs[(n+aind[val-1] - i)%n]++;
	}

	cout << *max_element(nmatchs.begin(),nmatchs.end()) << endl; 


	exit(0);
}
