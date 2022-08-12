#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> arr;

void solve() {
	arr.clear();
	arr.resize(2);
	int n,dn = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		dn *=2;
	if(n == 0) {
		cout << "! 1" << endl;
		return;
	} else if (n == 1) {
		cout << "? 1 2" << endl;
		int x;
		cin >> x;
		if(x == 1)
			cout << "! 1" << endl;
		else
			cout << "! 2" << endl;
		return;
	}
	for(int i = 0; i < dn; i++)
		arr[0].push_back(i+1);
	int x = 0, ao;
	while(arr[x].size() != 1) {
		arr[!x].clear();
		if(arr[x].size() == 2) {
			cout << "? " << arr[x][0] << ' ' << arr[x][1] << endl;
			cin >> ao;
			if(ao == 1)
				cout << "! " << arr[x][0] << endl;
			else
				cout << "! " << arr[x][1] << endl;
			return;
		} else if(arr[x].size() == 3) {
			cout << "? " << arr[x][0] << ' ' << arr[x][1] << endl;
			cin >> ao;
			if(ao == 0) {
				cout << "! " << arr[x][2] << endl;
				return;
			}
			int ao2 = ao == 2;
			cout << "? " << arr[x][ao2] << ' ' << arr[x][2] << endl;
			cin >> ao;
			if(ao == 1)
				cout << "! " << arr[x][ao2] << endl;
			else
				cout << "! " << arr[x][2] << endl;
			return;
		}
		for(int i = 0; i <= arr[x].size()-4; i+=4) {
			int as;
			cout << "? " << arr[x][i] << ' ' << arr[x][i+3] << endl;
			cin >> as;
			if(as == 1) {
				cout << "? " << arr[x][i] << ' ' << arr[x][i+2] << endl;
				cin >> as;
				if(as == 1)
					arr[!x].push_back(arr[x][i]);
				else
					arr[!x].push_back(arr[x][i+2]);
			}
			else if (as == 2) {
				cout << "? " << arr[x][i+1] << ' ' << arr[x][i+3] << endl;
				cin >> as;
				if(as == 2)
				arr[!x].push_back(arr[x][i+3]);
				else
				arr[!x].push_back(arr[x][i+1]);
			}
			else {
				cout << "? " << arr[x][i+1] << ' ' << arr[x][i+2] << endl;
				cin >> as;
				if(as == 1)
				arr[!x].push_back(arr[x][i+1]);
				else
				arr[!x].push_back(arr[x][i+2]);
			}
		}
		x = !x;
	}
	cout << "! " << arr[x][0] << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
