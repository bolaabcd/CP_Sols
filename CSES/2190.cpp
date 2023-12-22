#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
#define pii pair<ll,ll>

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

pii sub(pii p1, pii p2) {
	return {p1.f-p2.f,p1.s-p2.s};
}

ll sarea(pii p1, pii p2) {// area do vetor p1 com p2, do triangulo deles
	auto [x1,y1] = p1;
	auto [x2,y2] = p2;
	return x1*y2-y1*x2;
}

ll prod(pii p1, pii p2) {
	auto [x1,y1] = p1;
	auto [x2,y2] = p2;
	return x1*x2+y1*y2;
}

ll modsq(pii p) {
	return prod(p,p);
}

bool colin(pii p1, pii p2, pii p3) {
	return sarea(sub(p2,p1),sub(p3,p2)) == 0;
}

bool sig(ll v) {
	return v > 0;
}

void solve() {
	pii p1,p2,p3,p4;
	cin >> p1.f >> p1.s >> p2.f >> p2.s >> p3.f >> p3.s >> p4.f >> p4.s;
	pii p21 = sub(p2,p1), p31=sub(p3,p1), p41=sub(p4,p1);
	pii p43 = sub(p4,p3), p23=sub(p2,p3), p13=sub(p1,p3);
	

	if(p1 == p3 or p1 == p4 or p2 == p3 or p2 == p4)
		cout << "YES" << endl;
	else if(colin(p1,p2,p3) and colin(p1,p2,p4)) {
		if(prod(p21,p31) > 0 and prod(p21,p41) > 0) { // mesma dir os dois
			if(modsq(p31) > modsq(p21) and modsq(p41) > modsq(p21))
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		} else if(prod(p21,p31) < 0 and prod(p21,p41) < 0) { // Os 2 na direcao oposta
			cout << "NO" << endl;
		} else { // Um em cada direcao
            cout << "YES" << endl;
        }
	} else if(colin(p1,p2,p3)){
		if(modsq(p31) > modsq(p21) or prod(p21,p31) < 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	} else if(colin(p1,p2,p4)){
		if(modsq(p41) > modsq(p21) or prod(p21,p41) < 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	} else if(colin(p3,p4,p1)){
		if(modsq(p13) > modsq(p43) or prod(p43,p13) < 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	} else if(colin(p3,p4,p2)){
		if(modsq(p23) > modsq(p43) or prod(p43,p23) < 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	} else {
		if(sig(sarea(p21,p31)) != sig(sarea(p21,p41)) and sig(sarea(p43,p23)) != sig(sarea(p43,p13)))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

int main() { __
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
