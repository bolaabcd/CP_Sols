#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> arv;
// tipo de sorvete pra cor de todos
vector<int> ans;

// tipo de sorvete pra cor dos padrao
map<int,int> mapa;

// nodo pra tipos de sorvete
vector<set<int>> sets;
int msize = 0, psize=-1;

void dfs(int i, int pai) {
	set<int> proib;
	if(pai!= -1) {
		for(int j:sets[i]) {
			if(ans[j] != -1)
				proib.insert(ans[j]);
		}
		int lib = 0;
		for(int j:sets[i]) {
			if(ans[j] == -1){
				while(proib.count(lib))lib++;
				ans[j] = lib;
				proib.insert(lib);
			}
		}
	}
	for(int f: arv[i]){
		if(f == pai)
			continue;
		dfs(f,i);
	}
}


int main() { _
	int n,m;
	cin >> n >> m;

	sets.resize(n);
	arv.resize(n);
	ans.resize(m,-1);

	for(int i= 0; i < n; i++) {
		int si;
		cin >> si;
		for(int j = 0; j < si; j++) {
			int val;
			cin >> val;
			sets[i].insert(val-1);
		}
	}

	for(int i = 0; i < n-1; i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		arv[a].push_back(b);
		arv[b].push_back(a);
	}

	
	for(int i =0; i < n; i++ ) {
		int val = sets[i].size();
		if(val > msize){
			msize = val;
			psize = i;
		}
	}
	if(psize == -1){
		psize = 0;
		msize = 1;
		
	}

	int k = 0;
	for(int i : sets[psize]){
		ans[i] = k;
		mapa[i] = k++;
	}

	cout << msize << endl;

	dfs(psize,-1);

	for(int i = 0; i < m; i++){
		if(ans[i] == -1)
			ans[i] = 0;
		cout << ans[i]+1 << " ";
	}
	cout << endl;


	exit(0);
}