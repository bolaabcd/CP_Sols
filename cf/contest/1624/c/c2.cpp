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

		bool faio = false;
		vector<bool> marc(n,false);
		for(int i = 0; i < n; i++) {
            while( vec[i] != 0 && (vec[i] > n || (marc[vec[i]-1]))) vec[i] /= 2;
            if(vec[i] == 0){
                faio = true;
                break;
            }
            marc[vec[i]-1] = true;
		}

		if(faio)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	
	exit(0);
}
