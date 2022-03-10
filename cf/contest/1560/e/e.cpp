#include <bits/stdc++.h>

using namespace std;

#define _                         \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<char> characs;
string str;
//isi
//is

//abaaa
//aba
// int checa(string t, int i)
// {
// 	str = t.substr(0,++i);
// 	string stro = str;
// 	int j = 0;
// 	string finale = str;
// 	while(!str.empty()){
// 		for(;i < t.size() && j < str.size() && str[j] == t[i];i++, j++);
		
// 		char c;
// 		if (str.size() == j && t.size() == i){
// 			str = stro;
// 			characs.push_back(str[j-1]);
// 			return 1;
// 		}
// 		if (str.size() == j)
// 			c = t[i];
// 		else if (t.size() == i)
// 			c = str[j];
// 		else 
// 			c = t[i];

// 		bool foi = false;
// 		for(;j < str.size(); j++)
// 			if (str[j] == c){
// 				str.erase(j--);
// 				foi = true;
// 			}
// 		if(!foi){
// 			break;
// 		} else {
// 			characs.push_back(c);
// 		}
// 		finale += str;
// 	}
// 	stro = str;
// 	return finale == t;
	
// }



int checa(string t, int i) {

}

int main()
{
	_ int T;
	cin >> T;
	while (T--)
	{
		string t;
		cin >> t;
		t = t;
		bool foi = false;
		for (int i = 0; i < t.size(); i++)
		{
			characs = vector<char>();
			if (checa(t, i))
			{
				cout << str << " ";
				for (char c : characs)
				{
					cout << c;
				}
				foi = true;
				break;
			}
		}
		if (!foi)
			cout << -1;
		cout << endl;
	}
	exit(0);
}
