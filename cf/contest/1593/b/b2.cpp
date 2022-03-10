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
    while(t--) {
        string n;
        cin >> n;
        int siz = n.size();
        int p0=-1,s0=-1,p5=-1,p50=-1,p25=-1,p75=-1;
        for(int i = siz-1; i >= 0; i--) {
            switch (n[i])
            {
            case '0':
                if (p0==-1){
                    p0=i;
                } else if (s0==-1) {
                    s0=i;
                }
                break;
            case '2':
                if (p25==-1 && p5 > -1) {
                    p25 = i;
                }
                break;
            case '5':
                if (p5 == -1) {
                    p5 = i;
                }
                if (p50 == -1 && p0 > -1)
                    p50 = i;
                break;
            case '7':
                if (p75 == -1 && p5 > -1) {
                    p75 = i;
                }
                break;
            
            default:
                break;
            }
        }

        int ans=0;
        if (p0 == -1) p0 = -INF;
        if (p5 == -1) p5 = -INF;
        if (p50 == -1) p50 = -INF;
        if (p75 == -1) p75 = -INF;
        if (p25 == -1) p25 = -INF;
        if (s0 == -1) s0 = -INF;
        //int c0=siz-s0-1,c5=siz-p5-1;

        //cout << c0 + ((siz-c0-1)-p0-1) << endl;
        //cout << c5 + ((siz-c5-1)-p2-1) << endl;
        //siz - pultimo-1; se tiver o primeiro

        // cout << p25 << " " << p5 << " " << (p25 >= 0 && p25 < p5) << endl;
        ans = min(
            (s0 >= 0 && s0 < p0) ? siz - p0 -1 + (p0 - s0 - 1): INF,
            (p25 >= 0 && p25 < p5) ? siz - p5 -1 + (p5 - p25 - 1): INF
        );
        ans = min(ans,
            (p50 >= 0 && p50 < p0) ? siz - p0 -1 + (p0 - p50 - 1): INF
        );
        ans = min(ans,
            (p75 >= 0 && p75 < p5) ? siz - p5 -1 + (p5 - p75 - 1): INF
        );
        cout << ans << endl;
    }
	exit(0);
}
