#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5+10;

map<int,int> gr[MAX];// pra onde e qtdd
map<int,bool> grm[MAX];
bool mark[MAX];

int main() { __
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		gr[a][b]+=1;
		gr[b][a]+=1;
		grm[a][b] = false;
		grm[b][a] = false;
	}
	for(int i = 0; i < n; i++) {
		queue<int> q;
		q.push(i);
		while(!q.empty()) {
			int j = q.front();
			q.pop();
			if(mark[j])
				continue;
			mark[j] = true;
			for(auto [k,kk] : gr[j]) {
				if(!grm[j][k]) {
					grm[j][k] = true;
					grm[k][j] = true;
					for(int wow = 0; wow < kk; wow++)
					cout << j+1 << ' ' << k+1 << endl;
				}
				if(!mark[k])
					q.push(k);
			}
		}
	}
	exit(0);
}
