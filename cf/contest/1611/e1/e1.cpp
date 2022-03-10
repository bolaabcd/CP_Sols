#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> tree;
set<int> amgs;

vector<int> amgP;
int n,k;
int bfs(int pos){// recebe folha, retorna a dist do amg mais prox.
	queue<int> q;
	vector<bool> vis(n);
	q.push(pos);
	int dist = 0;
	int last = pos;
	while(!q.empty()) {
		int val = q.front();
		q.pop();
		if(vis[val])
			continue;
		vis[val] = true;
		if (last == val) 
			last = -1;
		if(amgs.count(val)) {
			return dist;
		}
		int lastT;
		for(int i: tree[val]) {
			q.push(i);
			if(last == -1 && !vis[i]) lastT = i;
		}
		if(last==-1){
			last = lastT;
			dist++;
		}
	}
	return -19;

	return dist;
}
vector<bool> visited;
int dist(int a,int b,int at) {
	if(visited[a])
		return -19;
	visited[a] = true;
	if(a==b)
		return at;
	for(int i: tree[a]) {
		int val = dist(i,b,at+1);
		if(val!=-19)
			return val;
	}
	return -19;
}

int main() { _
	int tot;
	cin >> tot;
	int t = tot;
	// if (tot == 10000) {
	// 	while(t--) {
	// 		if(tot-t != 65){
	// 			cin >> n >> k;
	// 			tree = vector<vector<int>>(n);
	// 			amgs = set<int>();

	// 			for(int i = 0; i < k; i++){
	// 				int amg;
	// 				cin >>amg;
	// 				amgs.insert(amg-1);
	// 			}
	// 			for(int i = 0; i < n-1; i ++) {
	// 				int a,b;
	// 				cin >> a >> b;
	// 				tree[a-1].push_back(b-1);
	// 				tree[b-1].push_back(a-1);
	// 			}
	// 		}
	// 		else {
	// 			cin >> n >> k;
	// 			cout << n << " " << k << endl;
	// 			tree = vector<vector<int>>(n);
	// 			amgs = set<int>();

	// 			for(int i = 0; i < k; i++){
	// 				int amg;
	// 				cin >>amg;
	// 				cout << amg << " ";
	// 				amgs.insert(amg-1);
	// 			}
	// 			cout << endl;
	// 			for(int i = 0; i < n-1; i ++) {
	// 				int a,b;
	// 				cin >> a >> b;
	// 				cout << a<< " "<< b << endl;
	// 				tree[a-1].push_back(b-1);
	// 				tree[b-1].push_back(a-1);
	// 			}
				
	// 			break;
	// 		}
	// 	}
	// } else
	while(t--) {
		cin >> n >> k;
		tree = vector<vector<int>>(n);
		amgs = set<int>();

		for(int i = 0; i < k; i++){
			int amg;
			cin >>amg;
			amgs.insert(amg-1);
		}
		for(int i = 0; i < n-1; i ++) {
			int a,b;
			cin >> a >> b;
			tree[a-1].push_back(b-1);
			tree[b-1].push_back(a-1);
		}

		amgP = vector<int>(n,-1);
		bool da = false;
		for(int i = 0; i < n; i++) {
			vector<int> &v = tree[i];
			if(v.size() == 1 && i!=0) {
				amgP[i] = bfs(i);
				assert(amgP[i]!= -19);
				visited = vector<bool>(n,false);
				int di = dist(0,i,0);
				assert(di != -19);
				if(di < amgP[i]){
					da = true;
					break;
				}
			}
		}

		if(da)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;


	}
	exit(0);
}

/*
1
10 3
4 5 9 
4 10
3 2
3 8
5 6
1 9
1 2
5 1
1 4
7 5

YES
*/