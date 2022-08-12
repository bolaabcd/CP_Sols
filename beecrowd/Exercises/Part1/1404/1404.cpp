#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n,m;
char tab[20][20];
bool marc[20][20];

pair<int,int> movs[] = {{-2,-2},{-2,2},{2,-2},{2,2}};

int ans;
int initx, inity;
void dfs(int i, int j, int amt) {
	ans = max(ans,amt);
	for(auto mov : movs) {
		int px = mov.first + i, py = mov.second + j;
		int pxmid = (px+i)/2, pymid = (py+j)/2;
		if(px >= 0 && py >=0 && px < n && py < m && tab[pxmid][pymid] == '2' && (tab[px][py] == '0' || marc[px][py] || (px == initx && py == inity)) && !marc[pxmid][pymid]){
			marc[pxmid][pymid] = true;
			dfs(px,py,amt+1);
			marc[pxmid][pymid] = false;
		}
	}

}

int main() { _
	while(1) {
		ans = 0;
		cin >> n >> m;
		if(n == 0 && m == 0)
			break;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if((i+j)%2 == 1)
					tab[i][j] = '3';
				else
					cin >> tab[i][j];
			}
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) 
				if(tab[i][j] == '1'){
					memset(marc,false,sizeof marc);
					initx = i, inity = j;
					dfs(i,j,0);
				}
		cout << ans << endl;
	}
	exit(0);
}
