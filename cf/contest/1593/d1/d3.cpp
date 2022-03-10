#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_withstdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define pb push_back
#define s second 
#define f first

typedef long long ll;
const int INF = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N, minimu,i=0,k;
vector<int> vec;

bool chutadora(int chute){
    //dbg(chute);
    for(int j=0;j<k;j++){
        int mod = vec[j];
        if(chute > 0) while(mod > minimu) mod -= chute;
        if(mod != minimu) return false;
    }
    return true;
}
int buscaBinaria(int maxChute, int minChute){
    if(maxChute == minChute){
        return maxChute;
    }
    int chute =  (maxChute + minChute + 1)/2;
    // dbg(chute);
    // dbg(maxChute);
    // dbg(minChute);
    bool res = chutadora(chute);
    if(res){
        return buscaBinaria(maxChute, chute);
    } else{
        return buscaBinaria(chute-1, minChute);
    }// T F
}

int main(){ 
    cin >> N;
    for(;i<N;i++){
        cin  >> k;
        vec = vector<int> (k);
        for(int j=0;j<k;j++){
            cin >> vec[j];
        }
        minimu = *min_element(vec.begin(), vec.end());
        int nem;
        if(chutadora(0)) nem = -1;
        else{

            int minChute = 1;
            int maxChute = 2e6;
            nem = buscaBinaria(maxChute,minChute);
        }
        cout << nem << endl;

    }
}
