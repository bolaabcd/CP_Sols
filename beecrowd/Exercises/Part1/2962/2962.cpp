#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int m, n, k, tk;
// sensor id -> {{x,y},sensibility}
vector<pair<pair<int,int>,int>> senss;
vector<bool> marc;
vector<vector<int>> gr;
// top, down, left, right
vector<bool> walls; 
void marcwalls(int sensid) {
	int x = senss[sensid].first.first, y = senss[sensid].first.second;
	if (y == n)
		walls[0] = true;
	if (y == 0)
		walls[1] = true;
	if (x == 0)
		walls[2] = true;
	if (x == m)
		walls[3] = true;
}

bool checkwalls() {
	if(
		(walls[0] && walls[1]) || // top-down
		(walls[0] && walls[3]) || // top-right
		(walls[1] && walls[2]) || // down-left
		(walls[2] && walls[3])    // right-left
		)
		return false;
	else
		return true;
}

bool find_problem(int i) {
	if(marc[i])
		return false;
	marc[i] = true;
	marcwalls(i);
	for(int node : gr[i]){
		find_problem(node);
	}
	return !checkwalls();
}

void addinwalls(int i) {
	assert(i >= 0);
	assert(i < senss.size());
	int x = senss[i].first.first, y = senss[i].first.second;
	senss.push_back({{x,0},0});
	senss.push_back({{x,n},0});
	senss.push_back({{0,y},0});
	senss.push_back({{m,y},0});
}

// see if we can pass between two sensors (avoiding square roots)
bool colision(int i, int j) {
	int x1 = senss[i].first.first, y1 = senss[i].first.second, x2 = senss[j].first.first, y2 = senss[j].first.second;
	int s1 = senss[i].second, s2 = senss[j].second;
	int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	return dist <= (s1 + s2) * (s1 + s2);
}

void create_graph() {
	for(int i = 0; i < k; i++) {
		// add fictional sensors in the walls, with 0 distance
		addinwalls(i);
	}
	tk = senss.size();
	gr.resize(tk);
	for(int i = 0; i < tk; i++)
		for(int j = i+1; j < tk; j++)
			if(colision(i,j)){
				gr[i].push_back(j);
				gr[j].push_back(i);
			}
}

int main() { _
	cin >> m >> n >> k;

	senss.resize(k);
	for(auto &pp: senss) cin >> pp.first.first >> pp.first.second >> pp.second;

	create_graph();

	marc.resize(tk,false);
	for(int i = 0; i < k; i++){
		walls.clear();
		walls.resize(4,false);
		if(!marc[i]) {
			if(find_problem(i)){
				cout << "N" << endl;
				exit(0);
			}
		}
	}
	cout << "S" << endl;
	exit(0);
}
