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
    vector<int> last(m,10);
    last[0] = -1;
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
                    if (grid[i][j]) {
                        ans[i][j]='C';
                    } else {
                        if (last[j-1]!=-1)
                            ans[i][j] =(!grid[i][j-1])||(cim == 'V') ?'V' : 'C';
                        else
                            ans[i][j]='V';
                    }
                    // char tlad = grid[i][j-1]?'F' : 'E';
                    // ans[i][j] = (tlad=='E' || cim == 'V' || !grid[i][j])&&!grid[i][j]?'V':'C';
                    // char tcim = grid[i-1][j]?'F' : 'E';
                    if (last[j] != -1) {
                        if (!grid[i][j])
                            last[j] = (lad=='V' || cim=='V')?10:-1;
                    }
                }
            }
        }
    }

    vector<int> amtFirst(m);
    amtFirst[0] = 1;
    for (int i = 1; i < m; i++) {
        amtFirst[i]=amtFirst[i-1] + (last[i] == -1);
    }


    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x1,x2;
        cin >> x1 >> x2;
        x1--, x2--;
        int tot;
        if (x1 == 0) {
            tot = amtFirst[x2];
        } else {
            tot = amtFirst[x2] - amtFirst[x1-1];
        }

        if ((x2-x1 == 0) || (tot == 1 && last[x1] == -1) || tot == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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


4 4
XXXX
X...
X.F.
X...
4
1 4
2 4
3 4
4 4

NO
YES
YES
YES


4 4
XXXX
X.F.
X.F.
X...
4
1 4
2 4
3 4
4 4

NO
NO
NO
YES
*/