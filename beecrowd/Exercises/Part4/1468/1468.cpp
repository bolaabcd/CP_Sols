#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pt;
typedef pair<pt,pt> bar;
typedef pair<pt,int> ptt;//point + timee of the last update

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e6+1;


vector<bar> vec;
int n, c;

// segtree de update em area e query em unidade
vector<ptt> dest(4*MAX+100);

void makeseg(int pos, int in, int fin) {
	if (in == fin) {
		dest[pos] = {{-2, -1},-1};
		return;
	}
	int mid = (in+fin)/2;
	makeseg(2*pos,in,mid);
	makeseg(2*pos+1,mid+1,fin);
	dest[pos] = {{-1,-1},-1};
}
int timee;
void update(int pos, int in, int fin, int l, int r, pt val) {
	if (r < in or l > fin)
		return;
	if (l <= in and fin <= r) {
		dest[pos] = {val, timee++};
		return;
	}
	
	int mid = (in+fin)/2;
	update(2*pos,in,mid,l,r,val);
	update(2*pos+1,mid+1,fin,l,r,val);
}

pt get_interv(bar ba) {
	return {min(ba.f.f, ba.s.f), max(ba.f.f, ba.s.f)};
}

ptt query(int pos, int in, int fin, int destt) {
	if(destt > fin or destt < in)
		return {{-1, -1},-1};
	if (in == fin and in == destt)
		return dest[pos];
	
	int mid = (in+fin)/2;
	ptt q1 = query(2*pos,in,mid,destt), q2 = query(2*pos+1,mid+1,fin,destt);
	assert(q1.f.f == -1 or q2.f.f == -1);
	assert(q1.f.f != -1 or q2.f.f != -1);
	if (q1.f.f != -1){
		if (q1.s > dest[pos].s or dest[pos].f.f == -1)
			return q1;
		else
			return dest[pos];
	} else {
		if (q2.s > dest[pos].s or dest[pos].f.f == -1)
			return q2;
		else
			return dest[pos];
	}
}
int maxix;
pt getfin(bar ba) {
	pt qr;
	if (ba.f.s == ba.s.s) // y igual
		return {-2, ba.s.s};
	else if (ba.f.s > ba.s.s) {
		qr = query(1,0,maxix,ba.f.f).f;
		if (qr.f == -2)
			qr.f = ba.f.f;
	}
	else { 
		qr = query(1,0,maxix,ba.s.f).f;
		if (qr.f == -2)
			qr.f = ba.s.f;
	}

	return qr;
}

int dirpos(bar ba) {
	if ((ba.f.s > ba.s.s and ba.f.f > ba.s.f) or (ba.f.s < ba.s.s and ba.f.f < ba.s.f))
		return 1;
	else if(ba.f.s == ba.s.s)
		return 0;
	else
		return -1;
}

int siga(pt v1, pt v2) {
	ll ans =  (ll(v1.f)*ll(v2.s) - ll(v2.f)*ll(v1.s));
	if (ans > 0)
		return 1;
	else if (ans < 0)
		return -1;
	else
		return 0;
}

pt subtr(pt p1, pt p2) {
	return {p1.f-p2.f,p1.s-p2.s};
}

int clockw(bar lhs, bar rhs) {
	if(lhs.s.s > lhs.f.s) {// fazendo o primeiro ponto ficar sendo o mais alto
		pt tmp = lhs.f;
		lhs.f = lhs.s;
		lhs.s = tmp;
	}
	if(rhs.s.s > rhs.f.s) {
		pt tmp = rhs.f;
		rhs.f = rhs.s;
		rhs.s = tmp;
	}
	pt v1 = subtr(lhs.f,lhs.s), v2 = subtr(rhs.f,lhs.s), v3 = subtr(rhs.s,lhs.s);// criando vetores centrados no mais baixo do lhs
	if (siga(v1,v2) > 0 and siga(v1,v3) > 0)
		return 1;
	else if (siga(v1,v2) < 0 and siga(v1,v3) < 0)
		return -1;
	else
		return 0;
}

bool intersectax(bar lhs, bar rhs) {
	int mil = min(lhs.f.f,lhs.s.f), mal = max(lhs.f.f,lhs.s.f);
	int mir = min(rhs.f.f,rhs.s.f), mar = max(rhs.f.f,rhs.s.f);
	if (mir <= mil and mil <= mar)
		return true;
	else if (mir <= mal and mal <= mar)
		return true;
	else
		return false;
}

int main() { _
	while(1) {
		cin >> n >> c;
		if(cin.eof())
			break;
		timee = 0;
		vec.clear();
		vec.resize(n);

		for (auto &v:vec) cin >> v.f.f >> v.f.s >> v.s.f >> v.s.s;
		sort(vec.begin(),vec.end(),[&](auto &lhs, auto &rhs) {
			//cout << lhs.f.f << ' ' << dirpos(lhs) << ' ' << clockw(lhs,rhs) << ' ' << clockw(rhs,lhs)  << ' ' << intersectax(lhs, rhs) <<endl;
			if (!intersectax(lhs, rhs) and max(lhs.f.s,lhs.s.s) != max(rhs.f.s,rhs.s.s))
				return max(lhs.f.s,lhs.s.s) > max(rhs.f.s,rhs.s.s);
			else if(!intersectax(lhs,rhs))
				return lhs > rhs;
			if (dirpos(lhs) == 1){
				if (clockw(lhs,rhs) != 0)
					return clockw(lhs, rhs) == -1;
				else if (dirpos(rhs) == 0)
					return rhs.s.s < min(lhs.f.s,lhs.s.s);
				else if (dirpos(rhs) == 1)
					return clockw(rhs, lhs) == 1;
				else
					return clockw(rhs,lhs) == -1;
			} else if (dirpos(lhs) == -1){
				if (clockw(lhs, rhs) != 0)
					return clockw(lhs, rhs) == 1;
				else if(dirpos(rhs) == 0)
					return rhs.s.s < min(lhs.f.s,lhs.s.s);
				else if(dirpos(rhs) == -1)
					return clockw(rhs, lhs) == -1;
				else
					return clockw(rhs,lhs) == 1;
			} else {
				assert(lhs.s.s == lhs.f.s); // temq ser horizontal
				return lhs.s.s > min(rhs.f.s,rhs.s.s);
			}
		});
		//for(auto v:vec)cout<<v.f.f << ' ' << v.f.s << ' ' << v.s.f << ' ' << v.s.s << endl;
		//exit(0);
		maxix = -1;
		for(auto v: vec) {
			if(v.f.f > maxix)
				maxix = v.f.f;
			if(v.s.f > maxix)
				maxix = v.s.f;
		}
		makeseg(1, 0, maxix);
		
		for(bar ba: vec) {
			pt inter = get_interv(ba);
			pt fini = getfin(ba);
			//cout << inter.f << ' ' << inter.s << "_" << fini.f << ' ' << fini.s << endl;
			update(1, 0, maxix, inter.f, inter.s, fini);
		}

		for(int i = 0; i < c; i++) {
			int x;
			cin >> x;
			pt ans = query(1, 0, maxix, x).f;
			if (ans.s == -1) {
				if (ans.f == -2)
					cout << x << endl;
				else if(ans.f != -1)
					cout << ans.f << endl;
				else
					cout << x << endl;
			}
			else if (ans.f == -2)
				cout << x << ' ' << ans.s << endl;
			else {
				cout << ans.f << ' ' << ans.s << endl;
				assert(ans.f != -1);
			}
		}

	}	
	exit(0);
}

