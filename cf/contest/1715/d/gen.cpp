#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int rand(int a, int b) {// [a,b]
    return rand()%(b-a+1) + a;
}

int n = 5,q = 3;
bool ok(set<tuple<int,int,int>> &tp) {
	vector<bool> proib(n,false);
	for(auto [a,b,c]:tp)
		if(!c)
			proib[a-1] = proib[b-1] = true;
	for(auto [a,b,c]:tp)
		if(c and proib[a-1] and proib[b-1])
			return false;
	return true;
}

int main(int argc, char** argv) {
    srand(atoi(argv[1]));
	cout << n << ' ' << q << endl;
	while(1){
		set<tuple<int,int,int>> tp;
		while(tp.size() != q) {
			int a = rand(1,n), b = rand(1,n);
			if(a > b)
				swap(a,b);
			tp.emplace(a,b,rand(0,1));
		}
		if(!ok(tp))
			continue;
		for(auto [i,j,x] : tp)
			cout << i << ' ' << j << ' ' << x << endl;
		break;
	}
}
