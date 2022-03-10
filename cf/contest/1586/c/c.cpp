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

int main() { _
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> grid(n,vector<bool>(m,false));
    for(auto& v: grid){
        for(int i = 0; i < m; i++) {
            char c;
            cin >> c;
            if (c != '.')
                v[i] = true;
        }
    }

    vector<vector<char>> ans(n,vector<char>(m));
    vector<int> tams(m,0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (i == 0 || j ==0) {
                ans[i][j] = grid[i][j]? 'F': 'E';
            } else {
                char cim = ans[i-1][j];
                char lad = ans[i][j-1];
                if (cim == 'E' || lad == 'E') {
                    ans[i][j] = grid[i][j]? 'F': 'E';
                }else {
                    ans[i][j] = 'X';
                    tams[j]++;
                }
            }
        }
    }

    vector<int> prefs(m);
    prefs[0] = tams[0];
    for (int i = 1; i < m; i++) {
        prefs[i]=tams[i]+prefs[i-1];
    }


    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x1,x2;
        cin >> x1 >> x2;
        x1--, x2--;
        int tot;
        if (x1 == 0) {
            tot = prefs[x2];
        } else {
            tot = prefs[x2] - prefs[x1-1];
        }

        if (tot && x2-x1 > 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

	exit(0);
}
/*
3 3
XXX
X..
X..
2
1 3
2 3

NO
YES
*/