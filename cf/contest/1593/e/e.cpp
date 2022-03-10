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
	int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        vector<set<int>> tree(n);

        for(int i = 0; i < n-1; i++) {
            int a,b;
            cin >> a >> b;
            tree[a-1].emplace(b-1);
            tree[b-1].emplace(a-1);
        }
        if (n == 1 || n == 2 ) {
            cout << 0 << endl;
            continue;
        }


        queue<int> inds2;
        for(int i = 0; i < n; i++) {
            if (tree[i].size() == 1)
                inds2.push(i);
        }

        int ans = n;
        while (1) {
            queue<int> inds;
            while(!inds2.empty()) {
                int i = inds2.front();
                inds2.pop();
                ans--;
                int j = *tree[i].begin();
                tree[j].erase(i);
                if (tree[j].size() == 1) {
                    inds.push(j);
                }
                tree[i] = set<int>();
            }
            k--;
            if (inds.empty() || !k)
                break;
            inds2=inds;
        }


        cout << ans << endl;

    }
	exit(0);
}
