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
    vector<int> a(n), maxl(n), maxr(n);
    for(int& i: a) cin >> i;
    int prevl = 0, prevr = 0, maxi = -INF;
    for(int i = 0; i < n; i++)
        maxl[i] = min(prevl+1,a[i]), prevl = maxl[i];
    for(int i = n-1; i >= 0; i--)
        maxr[i] = min(prevr+1,a[i]), prevr = maxr[i];
    for(int i = 0; i < n; i++)
        maxi = max(maxi,min(maxl[i],maxr[i]));
    cout << maxi << endl;
	exit(0);
}

