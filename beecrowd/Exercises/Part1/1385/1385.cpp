#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<string> nums;
vector<vector<short>> tnums;
short amt;

bool set_nums(int p, string numbers, vector<short> &vec) {
	assert(numbers[0] != ' ');
	if(numbers.size() >= 2 && numbers[1] == '0' && numbers[0] == '0')
		return false;
	short amtspace = 0;
	string numat;
	short sum = 0;
	for(short i = 0; i < numbers.size(); i++) {
		if(i >= 2 && numbers[i] != ' ' && numbers[i-1] == '0' && numbers[i-2] == ' ') {
			return false;
		}
		if(numbers[i] == ' ') {
			assert(amtspace < amt-1);
			vec[amtspace] = atoi(numat.c_str());
			sum += vec[amtspace];
			amtspace++;
			numat = "";
		} else {
			numat.push_back(numbers[i]);
		}
	}
	assert(amtspace == amt-1);
	vec[amtspace] = atoi(numat.c_str());
	if(vec[amtspace] != sum)
		return false;
	return true;
}

bool check_parc(vector<short> &vec) {
	short sum = 0;
	for(short i = 0; i < vec.size()-1; i++){
		sum += vec[i];
		if (sum > vec[vec.size()-1])
			return false;
	}

	return sum == vec[vec.size()-1];
}

vector<vector<int>> masks;
void create_masks_size(int size_we_want, int max_pos, int pos, int current) {
	int size_we_need = size_we_want-__builtin_popcount(current);
	if(size_we_need == 0){
		masks[size_we_want-1].push_back(current);
		return;
	}
	if(max_pos - pos < size_we_need)
		return;
	create_masks_size(size_we_want,max_pos,pos+1,current);
	create_masks_size(size_we_want,max_pos,pos+1,current|(1 << pos));
}
void create_masks(int max_ones, int max_poss) {
	masks.resize(max_ones);

	for(int no = 1; no <= max_ones; no++) {
		create_masks_size(no, max_poss, 0, 0);
		sort(masks[no-1].begin(), masks[no-1].end());
	}

}

// p, k, number position
vector<vector<vector<short>>> tnumss;

// number of ones, mask position
bool get_nums(short p, int maskpos, int tpos) {
	int mask = masks[amt-1-1][maskpos];
	if(mask >= (1 << (nums[p].size()-1)))
		return false;

	assert(__builtin_popcount(mask) == amt-1);

	string ans;
	ans.push_back(nums[p][0]);
	for(int i = 1, j = 1; i < (1<<(nums[p].size()-1)) ; i = i << 1, j++) {
		if(i & mask){
			ans.push_back(' ');		
		} 
		assert(j >= 0 && j < nums[p].size());
		ans.push_back(nums[p][j]);
	}

	return set_nums(p,ans,tnumss[p][tpos]);
}

vector<short> prevvals;
bool get_tnums(short p, short k) {
	if(p >= tnumss.size())
		return false;
	if(k >= tnumss[p].size())
		return false;
	prevvals[p] = k;
	if(p == tnums.size()-1) {
		for(short i = 0; i < amt; i++) {
				short sumtot = 0;
				for(short j = 0; j < tnums.size()-1; j++){
					assert(tnumss[j][prevvals[j]].size() == amt);
					sumtot += tnumss[j][prevvals[j]][i];
				}
				if(sumtot != tnumss[p][prevvals[p]][i])
					return get_tnums(p,k+1);
			}
		return true;
	} else if (get_tnums(p+1,0))
		return true;
	else
		return get_tnums(p,k+1);
}

int t;
void solve() {
	nums.clear();
	tnums.clear();
	string s;
	cin >> s;
	assert(s[0] == 'P');
	cout << 'P';
	short pos = 1;
	for(short i = 1; i < s.size(); i++) {
		if(s[i] == 'P' || s[i] == 'T')
			cout << ' ';
		if(s[i] == 'P')
			pos = i+1;
		cout << s[i];
	}
	cout << endl;
	assert(cin.peek() == '\n');
	cin.get();
	// Printed first line

	string num;
	for(short i = pos; i < s.size() && s[i] >= '0' && s[i] <= '9'; i++)
		num.push_back(s[i]);
	amt = atoi(num.c_str());
	// number of numbers to generate per client, including totals
	amt++;


	vector<string> names;
	string name;
	while(name != "TP") {
		string numtmp;
		name = "";
		while(cin.peek() < '0' || cin.peek() > '9'){
			name.push_back(cin.get());
		}
		names.push_back(name);

		while(cin.peek() != '\n') {
			numtmp.push_back(cin.get());
		}
		cin.get();
		nums.push_back(numtmp);
	}

	assert(names.size() == nums.size());
	tnums.resize(nums.size(),vector<short>(amt,-1));

	tnumss.clear();
	tnumss.resize(nums.size());

	for(int i = 0; i < nums.size(); i++) {
		int k = 0;
		tnumss[i].clear();
		tnumss[i].resize(1,vector<short>(amt,-1));
		//amt-1 is the number of spaces, masks is 0-based
		for(int j = 0; j < masks[amt-1-1].size(); j++) {
			if(get_nums(i,j,k)) {
				k++;
				tnumss[i].resize(tnumss[i].size()+1,vector<short>(amt,-1));
			}			
		}
		tnumss[i].resize(tnumss[i].size()-1);
		assert(tnumss[i].size() > 0);
		if(nums[i][0] != '1')
			reverse(tnumss[i].begin(), tnumss[i].end());
	}

	prevvals.clear();
	prevvals.resize(tnums.size());
	assert(get_tnums(0,0));
	for(int i = 0; i < tnums.size(); i++) {
		tnums[i] = tnumss[i][prevvals[i]];
	}

	for(short i = 0; i < names.size(); i++) {
		cout << names[i];
		assert(tnums[i].size() == amt);
		for(short j = 0; j < amt; j++){
			assert(tnums[i][j] != -1);
			cout << ' ' << tnums[i][j];
		}
		cout << endl;

	}
}

int main() { _
	cin >> t;
	create_masks(5,24);
	while(t--) {
		solve();
	}
	exit(0);
}
