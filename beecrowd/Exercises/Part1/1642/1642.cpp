#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int m;
	while (1){
		cin >> m;
		if(m == 0)
			break;
		string s;
		if(cin.peek() == '\n')
			cin.get();
		getline(cin,s);
		
		map<char,int> se;
		set<char> conj; 
		int maxi = 0, n = s.size();
		
		for(int i = 0, j = -1; i < n; ) {
			if(conj.size() <= m) {
				maxi = max(maxi,j-i+1);
				j++;
				if(j >= n)
					break;
				se[s[j]]++;
				conj.insert(s[j]);
			} else if (conj.size() > m){
				assert(se[s[i]] > 0);
				se[s[i]]--;
				if(se[s[i]] == 0)
					conj.erase(s[i]);
				i++;
			}
		}
		
		cout << maxi << endl;
	}
	
	
	exit(0);
}
