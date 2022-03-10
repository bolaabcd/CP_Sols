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

vector<vector<int>> tree;

vector<int> heights;
vector<bool> visited;
int dfs(int atual) {
    if (visited[atual])
        return heights[atual];
    visited[atual] = true;


    if (tree[atual].size() == 1){
        return heights[atual] = 0; 
    }
    int menalt = INF;
    for(int& prox : tree[atual]) {
        menalt = min(menalt,dfs(prox));
    }
    return heights[atual] = menalt+1;
}

int main() { _
    int t;
    cin >> t;
    char nl[3];
    cin.read(nl,1);
    int n,k;
    cin >> n >> k;
    cout << n <<" " <<  k << " "<< nl << endl;

    for(int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
    }

    return 0;
}
