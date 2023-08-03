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
	vector<int> pre(n),in(n);
	for(int&i:pre)
		cin >> i;
	for(int&i:in)
		cin >> i;
	vector<bool> viu(n+1,false);
	stack<int> pil;
	int i = 0, j = 0;
	while(i != n and j != n) {
		assert(i < n and j < n);
		while(pre[i] != in[j]) {
			viu[pre[i]] = true;
			pil.push(pre[i]);
			i++;
		}
		pil.push(pre[i]);
		i++;
		j++;
		while(viu[in[j]]) {
			while(pil.top() != in[j]) {
				cout << pil.top() << ' ';
				pil.pop();
			}
			j++;
		}
	}
	while(!pil.empty()) {
		cout << pil.top() << ' ';
		pil.pop();
	}
	cout << endl;
	exit(0);
}
