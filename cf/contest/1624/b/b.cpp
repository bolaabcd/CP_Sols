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
		int a,b,c;
		cin >> a >> b >> c;
		int vaa = b-(c-b), vab = a+(c-a)/2, vac = b+(b-a);
		if((a <= vaa && vaa%a == 0) || (c <= vac && vac%c == 0) || (b <= vab && (c-a)%2==0 && vab%b == 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	exit(0);
}
