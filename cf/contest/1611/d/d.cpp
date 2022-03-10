#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// vector<vector<int>> gtree;
vector<int> perm;

// int dfs(int p, int maiorJaFoi) {
// 	perm[p] = 1 + maiorJaFoi;
// 	for(int i = 0; i < gtree[p].size(); i++) {
// 		maiorJaFoi = max(dfs(gtree[p][i],maiorJaFoi),maiorJaFoi);
// 	}
// }

int main() { _
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> b(n);
		for(int& i: b) cin >> i;
		vector<int> p(n);
		vector<int> indp(n+1,-1);
		for(int i = 0;i<n; i++){
			cin >> p[i];
			indp[p[i]] = i;
		}

		bool foi = true;
		for(int i= 0; i < n; i++) {
			//b[i] e pai de i+1
			//Portanto ind(i+1,p) > ind(b[i],p)
			if (indp[i+1] < indp[b[i]]){
				foi = false;
				break;
			}
		}

		if(!foi)
			cout << -1 << endl;
		else {
			vector<vector<int>> tree(n);
			int raiz = -1;
			for(int i = 0; i < n; i++) {
				tree[b[i]-1].push_back(i);
				if(b[i] == i+1)
					raiz = i+1;
			}
			// gtree=tree;
			assert(raiz!=-1);
			perm=vector<int>(n,0);
			//Aponta pro ultimo filho
			int maiorRaiz = 0;
			vector<int> alts(n+1,0);
			for(int val:p) {
				if(raiz != val){
					perm[val-1] = maiorRaiz-alts[b[val-1]]+1;
					maiorRaiz = max(maiorRaiz,perm[val-1]+alts[b[val-1]]);
					alts[val] = perm[val-1] + alts[b[val-1]];
				}
			}
			// vector<int> lastFilho(n+1,-1);
			// for(int val:p) {
			// 	if(raiz != val){
			// 		int soma = 0;
			// 		//recuperando maior soma ate agora
			// 		for(int j = b[val-1]; lastFilho[j] != -1 ; j = lastFilho[j]) {
			// 			// if(lastFilho[j] != -1)
			// 			soma += perm[lastFilho[j]-1];
			// 		}
			// 		//perm[val-1]=++maiorAteAgr[b[val-1]];
			// 		perm[val-1] = soma + 1;
			// 		lastFilho[b[val-1]] = val;

			// 	}
			// }
			

			for(int val:perm) cout << val << " ";
			cout << endl;
		}
	}
	exit(0);
}
/*
1
7
1 1 1 2 2 3 3
1 2 3 4 5 6 7
*/