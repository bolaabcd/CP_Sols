#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 2e5+100;
int m;
ll as[2][MAX], fowmax[2][MAX], fowmaxii[2][MAX], fowmaxii2[2][MAX];

ll front(int i, int j, ll tim) {
	ll maxx = fowmax[j][i], maxxi = fowmaxii[j][i];
	//cout << i << ' ' << j << ' ' << tim << endl;
	assert(maxxi >= i);
	if(tim == 0 and maxxi == i) {
		return tim+m-i-1;
	} else if(maxxi == i)
		assert(tim+maxxi-i-1 >= maxx);
	if(tim+maxxi-i-1 < maxx)
		return maxx + m - maxxi;
	else
		return tim+m-i-1;
}

ll back(int i, int j, ll tim) {
	ll maxx = fowmax[j][i], maxxi = fowmaxii2[j][i];
	//cout << i << ' ' << j << ' ' << tim << '_' <<maxx << ' ' << maxxi << endl;
	if(maxxi == m-1)
		assert(maxx <= tim+m-maxxi-2);
	assert(maxxi >= i);
	if(tim+m-maxxi-2 < maxx)
		return maxx+maxxi-i+1;
	else
		return tim+m-i-1;
}

void solve() {
	cin >> m;
	for(int j = 0; j < 2; j++)
		for(int i = 0; i < m; i++) {
			cin >> as[j][i];
			fowmax[j][i]    = as[j][i];
			fowmaxii[j][i]  = i;
			fowmaxii2[j][i] = i;
		}
	//cout << (as[0][2] == fowmax[0][3]) << "x" << endl;
	for(int j = 0; j < 2; j++) {
		for(int i = m-2; i >= 0; i--) {
			if(as[j][i] >= fowmax[j][i+1])
				fowmaxii[j][i] = i;
			else
				fowmaxii[j][i] = fowmaxii[j][i+1];
			if(as[j][i] > fowmax[j][i+1])
				fowmaxii2[j][i] = i;
			else
				fowmaxii2[j][i] = fowmaxii2[j][i+1];
			fowmax[j][i] = max(fowmax[j][i+1],as[j][i]);
		}
	}
	int x = 0;
	ll tim = 0, mini = LINF;
	cout << front(0,0,0) << "WOW" << fowmax[0][0] << ' ' << fowmaxii[0][0]<< endl;
	for(int i = 0; i < m; i++) {
		tim = max(tim,as[x][i])+1;
		if(i == 0)
			tim = 0;
		assert(front(i,x,tim)-tim >= 0);
		ll gonow = tim + front(i,x,tim)-tim;
		//cout << tim << ' ' << front(i,x,tim) << endl;
		gonow = max(gonow, as[!x][m-1])+1;
		//cout << gonow << endl;
		assert(back(i,!x,gonow)-gonow >= 0);
		gonow += back(i,!x,gonow)-gonow;
		//cout << back(i,!x,gonow)-gonow << endl;
		//cout << 'A' << gonow << endl;
		mini = min(mini, gonow);
		x = !x;
		tim = max(tim,as[x][i])+1;
	}
	cout << mini << endl;
}

int main() { //_
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
