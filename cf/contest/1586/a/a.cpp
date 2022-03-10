#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

void debug_out(string s, int line) { cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t) {
    if (s[0] != ',') cerr << "Line(" << line << ") ";
    do { cerr << s[0]; s = s.substr(1);
    } while (s.size() and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}
#ifdef DEBUG
#define debug(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
#define debug(...)
#endif

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
set<int> prims;

void solve(vector<int>& vec, int soma,int n){
	if (!prims.count(soma)) {
			cout << n << endl;
			for(int i = 1; i < n+1; i++) cout << i << " ";
			cout << endl;
			return;
		}

		for (int i = 0; i< n; i++) {
			soma -= vec[i];
			if (!prims.count(soma)) {
				cout << n-1 << endl;
				for(int j = 1; j < n+1; j++) if(j != i+1)cout << j << " ";
				cout << endl; 
				return;
			}
			soma += vec[i];
		}

		for (int i = 0; i< n; i++) {
			soma -= vec[i];
			for(int j = i+1; j < n; j++) {
				soma -= vec[j];
				if (!prims.count(soma)) {
					cout << n-2 << endl;
					for(int r = 1; r < n+1; r++)if(r != i+1 && r != j+1) cout << r << " ";
					cout << endl; 
				}	
				soma += vec[j];
			}
			soma += vec[i];
		}
		for (int i = 0; i< n; i++) {
			soma -= vec[i];
			for(int j = i+1; j < n; j++) {
				soma -= vec[j];
				for (int k = j+1; k < n; k++) {
					soma -= vec[k];
					if (!prims.count(soma)) {
						cout << n-3 << endl;
						for(int r = 1; r < n+1; r++)if(r != i+1 && r != j+1 && r!= k+1) cout << r << " ";
						cout << endl; 
					}
					soma +=vec[k];
				}
				soma += vec[j];
			}
			soma += vec[i];
		}
}

int main() { _
	int t;
	cin >> t;
	prims.insert(2);
	for(int j = 3; j < 20000+10; j+=2){
		bool entrou = false;
		for(int i : prims){
			if (j % i == 0){
				entrou = true;
				break;
			}
		} 
		if(!entrou)
		prims.insert(j);

	}
	while(t--) {
		int n;
		cin >> n;
		vector<int> vec(n);
		int soma = 0;
		for(int& v: vec) cin >> v, soma += v;

		solve(vec,soma,n);
	}
	exit(0);
}
