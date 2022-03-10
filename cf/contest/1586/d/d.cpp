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
    // if (ans == i) ans = -1;
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
    // if (ans == i) ans = -1;
    return ans;
}

int main() { 
    cin >> n;
    vector<int> ante(n,-1);
    int first, last;
    for(int i = n; i>0; i--) {
        int ant = antec(i);
        if (ant == 0) {
            first = i;
            continue;
        }
        if (ant == i)
            continue;
        ante[i-1] = ant-1;
    }
    for(int i = n; i>0; i--) {
        int next = sucec(i);
        if (next == 0) {
            last = i;
            continue;
        }
        if (next == i)
            continue;
        ante[next-1] =i-1;
    }


    list<int> inds;    
    for(int i = last;  ; i = ante[i-1]+1) {
        inds.push_front(i);
        if (i==first)
            break;
    }

    vector<int> ans(n);
    int at = 1;
    for (int i: inds) {
        ans[i-1] = at++;
    }

    cout << "! ";
    for(int a: ans) cout << a << " ";
    cout << endl;
    
	exit(0);
}
