#include <bits/stdc++.h>
using namespace std;

set<string> joias;
int main(){
    string s;
    while(cin>>s){
        joias.insert(s);
    }
    cout<<joias.size()<<endl;
}