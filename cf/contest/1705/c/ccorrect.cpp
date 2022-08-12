#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define forC(i,k,n) for(int i=k;i<n;i++)
#define forD(i,k,n) for(int i=k;i>=n;i--)
#define read(v) for(auto &elm : v) cin >> elm
#define readM(v) for(auto rr : vv) for(auto ee : rr) cin >> ee
#define print(var) cout << var << endl
#define printV(l) for(auto a : l) cout << a << " "; cout << endl
#define printM(mm) for(auto aaa : mm){ for(auto b : aaa) cout << b << " "; cout << endl;}
#define printPair(p) cout << p.first << " " << p.second << endl 
#define dbgPair(p) cout << #p << " = " <<   p.first << " " << p.second << endl 
#define bk cout << endl
#define hr cout << "_______________________________________" << endl
#define vi vector<int>
#define vll vector<long long int>
#define vs vector<string>
#define vb vector<bool>
#define vc vector<char>
#define vii vector<pair<int,int>>
#define dbg(x) cout << #x << " = " << x << endl
#define dbgV(l) cout << #l << endl; for(int i=0;i<l.size();i++) cout << #l << "[" << i<< "] : "<< l[i] << endl
#define dbgM(mm) cout << #mm << endl; for(auto aaa : mm){ for(auto b : aaa) cout << b << " "; cout << endl;}  
#define all(x) x.begin(),x.end()
#define pb push_back
#define s second 
#define f first
#define eb emplace_back
#define ef emplace_front
#define pf push_front

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3fll;


void tc(){
    map<ll,ll> vPos;
    string s;
    int n,c,q; cin >> n >> c >> q;
    cin >> s;
    ll len = n;
    vPos.insert({1,1});
    while(c--){
        ll i,j; cin >> i >> j;
        //dbg(len);
        i--,j--;
        vPos[len] = i;
        len += j-i+1;
    }
    while(q--){
        ll k; cin >> k;
        k--;
        while(k >= n){
            auto  it = vPos.lower_bound(k);
            if(it == vPos.end() || (*it).f > k) it--; 
            auto p = (*(it));
            k = (k-p.f)+p.s;
        }
        print(s[k]);
    }

}

int main(){ _
    int ttt; cin >>  ttt;
    while(ttt--) tc();
}
