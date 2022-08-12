#include<bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define read(x) for(auto& qw : (x)) cin >> qw;
//#define endl "\n"; //para problemas iterativos comentar essa linha
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9 + 7;
const ll NO_OPERTATION = -1;
const double eps = 1e-8;
const int MAX = 200000 + 100;
const int LOG = 20;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pii> v;
    ll n, s, x;
    cin>>n>>s>>x;
    bool confere=false;
    vector<bool> visi(n+10);
    int qnts=0;
    ll lmelhor = 0;
    ll nmelhor = 0;
    cout<<"? "<<s<<endl;
    cin>>lmelhor>>nmelhor;
	nmelhor = s;
    if(lmelhor==x)
    {
        cout<<"! "<<x<<endl;
        return 0;
    }
    for(int i=1;i<=998;i++)
    {
       int aux = uniform(1,n);
       while(visi[aux]!=0)
       {
           aux = uniform(1,n);
       }
       qnts++;
       visi[aux]=1;
       cout<<"? "<<aux<<endl;
       ll valor, next;
       cin>>valor>>next;
       if(valor==x)
       {
           cout<<"! "<<valor<<endl;
           confere=1;
           return 0;
       }
       else
       {
           if(valor<x and valor>lmelhor)
           {
               lmelhor=valor;
               nmelhor=next;
           }
       }
       if(qnts==n){break;}
    }
    for(int i=1;i<=999;i++)
    {
        if(nmelhor==-1){break;}
        cout<<"? "<<nmelhor<<endl;
        cin>>lmelhor>>nmelhor;
        if(lmelhor>=x){cout<<"! "<<lmelhor<<endl; confere=1; break;}
    }
    if(!confere){cout<<-1<<endl;}
    return 0;
}
