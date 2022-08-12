#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	while(1) {
		int n;
		cin >> n;
		if(cin.eof())
			break;
		vector<bool> qsp(3,true);
		queue<int> q;
		stack<int> s;
		priority_queue<int> p;

		for(int i = 0; i < n; i++) {
			int op, x;
			cin >> op >> x;
			if(op == 1){
				q.push(x);
				s.push(x);
				p.push(x);
			} else {
				if(q.front() != x)
					qsp[0] = false;
				if(s.top() != x)
					qsp[1] = false;
				if(p.top() != x)
					qsp[2] = false;
				q.pop();
				s.pop();
				p.pop();
			}
		}

		int tot = qsp[0]+qsp[1]+qsp[2];
		if(tot == 0)
			cout << "impossible";
		else if (tot >= 2)
			cout << "not sure";
		else if (qsp[0])
			cout << "queue";
		else if (qsp[1])
			cout << "stack";
		else
			cout << "priority queue";
		cout << endl;
	}
	exit(0);
}
