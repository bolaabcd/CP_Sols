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
    int n = 3, m = 1000;

/*
733.2X2.4X14.1X2.3X239.

739.2X14.1X2.1X1.2X238.

755.2X1.1X2.1X238.
*/
    vector<vector<char>> grid(n,vector<char>(m));
    int amt = 0;
    int i;
    for (i = 0; amt < 733; i++) {
        grid[0][i] = '.';
        amt++;
    }
    amt = 0;
    for (; amt < 2; i++) {
        grid[0][i] = 'X';
        amt++;
    }
    amt = 0;
    for (; amt < 2; i++) {
        grid[0][i] = '.';
        amt++;
    }
    amt = 0;
    for (; amt < 4; i++) {
        grid[0][i] = 'X';
        amt++;
    }
    amt = 0;
    for (; amt < 14; i++) {
        grid[0][i] = '.';
        amt++;
    }
    amt = 0;
    for (; amt < 1; i++) {
        grid[0][i] = 'X';
        amt++;
    }
    amt = 0;
    for (; amt < 2; i++) {
        grid[0][i] = '.';
        amt++;
    }
    amt = 0;
    for (; amt < 3; i++) {
        grid[0][i] = 'X';
        amt++;
    }
    amt = 0;
    for (; amt < 239; i++) {
        grid[0][i] = '.';
        amt++;
    }
    //739.2X14.1X2.1X1.2X238.
    for (i = 0; amt < 739; i++) {
        grid[1][i] = '.';
        amt++;
    }
    amt = 0;
    for (; amt < 2; i++) {
        grid[1][i] = 'X';
        amt++;
    }
    amt = 0;
    for (; amt < 14; i++) {
        grid[1][i] = '.';
        amt++;
    }
    amt = 0;
    for (; amt < 1; i++) {
        grid[1][i] = 'X';
        amt++;
    }
    amt = 0;
    for (; amt < 2; i++) {
        grid[1][i] = '.';
        amt++;
    }
    amt = 0;
    for (; amt < 1; i++) {
        grid[1][i] = 'X';
        amt++;
    }
    amt = 0;
    for (; amt < 1; i++) {
        grid[1][i] = '.';
        amt++;
    }
    amt = 0;
    for (; amt < 2; i++) {
        grid[1][i] = 'X';
        amt++;
    }
    amt = 0;
    for (; amt < 238; i++) {
        grid[1][i] = '.';
        amt++;
    }
    //755.2X1.1X2.1X238.
    for (i = 0; amt < 755; i++) {
        grid[2][i] = '.';
        amt++;
    }
    amt = 0;
    for (; amt < 2; i++) {
        grid[2][i] = 'X';
        amt++;
    }
    amt = 0;
    for (; amt < 1; i++) {
        grid[2][i] = '.';
        amt++;
    }
    amt = 0;
    for (; amt < 1; i++) {
        grid[2][i] = 'X';
        amt++;
    }
    amt = 0;
    for (; amt < 2; i++) {
        grid[2][i] = '.';
        amt++;
    }
    amt = 0;
    for (; amt < 1; i++) {
        grid[2][i] = 'X';
        amt++;
    }
    amt = 0;
    for (; amt < 238; i++) {
        grid[2][i] = '.';
        amt++;
    }

    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++) {
            cout << grid[i][j];
        }
        cout << endl;
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