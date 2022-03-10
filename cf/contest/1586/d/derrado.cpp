#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
int antec(int i) {
    string s = "? ";
    for  (int j = 1; j < n+1; j++) {
        if (j == i)
            s.append("1 ");
        else
            s.append("2 ");
    }
    cout << s << endl;
    int ans;
    cin >> ans;
    return ans;
}

int sucec(int i) {
    string s = "? ";
    for  (int j = 1; j < n+1; j++) {
        if (j == i)
            s.append("2 ");
        else
            s.append("1 ");
    }
    cout << s << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() { 
    cin >> n;
    deque<int> dq;
    dq.push_back(1);
    
    for(int prev = 1; prev = antec(prev); dq.push_front(prev));
    for(int next = 1; next = sucec(next); dq.push_back (next));

    vector<int> ans(n);
    int at = 1;
    for(int& i: dq) ans[i] = at++;

    for(int a: ans) cout << a << " ";
    cout << endl;
    
	exit(0);
}
