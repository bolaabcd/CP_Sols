#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { __
	int n,k;
	cin >> k;
	string s;
	cin >> s;
	n = s.size();
	vector<int> amts(26);
	for(int i = 0; i < n; i++)
		if(s[i] != '?')
			amts[s[i]-'a']++;
	for(int i = 0; i < (n+1)/2; i++) {
		if(s[i] =='?' and s[n-1-i] == '?') {
			continue;
		} else if(s[i] == s[n-i-1])
			continue;
		else if(s[i] == '?') {
			s[i] = s[n-1-i];
			amts[s[i]-'a']++;
		} else if (s[n-1-i] == '?') {
			s[n-1-i] = s[i];
			amts[s[i]-'a']++;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}
	for(int i = k; i < 26; i++)
		if(amts[i]) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	int kk = k-1;
	for(int i = (n+1)/2-1; i >= 0; i--) {
		while(kk > 0 and amts[kk])
			kk--;
		if(s[i] == '?') {
			s[i] = 'a'+kk;
			s[n-i-1] = s[i];
			amts[kk] += 2;
		}
	}
	/*
	int sub = 0, quero = k, tem = 0;
	for(int i = 0; i < k; i++)
		tem += amts[i] != 0;
	for(int i = 0; i < n; i++)
		sub += s[i] == '?';
	sub = (sub/2) + (sub%2);
	int repet = sub - (quero - tem);
	if(repet < 0) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	int kk = 0;
	for(int i = 0; i < n; i++) {
		while(kk < k and !repet and amts[kk])
			kk++;
		if(s[i] == '?') {
			s[i] = 'a'+kk;
			s[n-i-1] = s[i];
			amts[kk]+=2;
			repet--;
		}
	}
	*/
	for(int i = k; i < 26; i++)
		if(amts[i]) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	for(int i = 0; i < k; i++)
		if(!amts[i]) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	
	for(int i = 0; i < n; i++)
		if(s[i] == '?' or (s[i] != s[n-i-1])) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}


	cout << s << endl;
	exit(0);
}
