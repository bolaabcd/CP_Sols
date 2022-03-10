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
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> vec(n);
		for(int& i:vec) cin >> i;

		vector<int> cnt(n,0);
		for(int i = 0; i < n; i++) {
			while (vec[i] > n) vec[i]/=2;
			cnt[vec[i]-1]++;
		}

		bool faio = false;
		for(int i = n-1; i >= 0; i --) {
			if(cnt[i] == 0){
				faio = true;
				break;
			} else if(cnt[i] > 1) {
				int amt = cnt[i] - 1;
				cnt[i] = 1;
				cnt[(i+1)/2-1] += amt;
			}
		}
		if(faio)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	
	exit(0);
}
