#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n,d;		
int tiraeve(int pr, vector<int>& mimimi,vector<int> & vec, int dum, int mini) {
	if(pr == n-1){
		dum = d-vec[n-2];
	}
	int minew = INF, maxi = dum;
	for(int i = 0; i < n; i++) {
		if(i == pr)
			continue;
		if(i == pr+1 && pr != 0){
			maxi = max(maxi,vec[pr+1]-vec[pr-1]-1);
			// minew = min(minew,vec[pr+1]-vec[pr-1]-1);
		}
		else if(i == pr+1 && pr == 0){
			maxi = max(maxi,vec[pr+1]-1);
			// minew = min(minew, vec[pr+1]-1);
		}
		else{
			maxi = max(maxi,mimimi[i]);
			// minew = min(minew,mimimi[i]);
		}
	}
	bool pulou = false;
	if((maxi-1)/2 <= dum-1){
		dum--;
		minew = dum;
		pulou = true;
	}
	for(int i = 0; i < n; i++) {
		if(i == pr)
			continue;
		if(i == pr+1 && pr != 0){
			int valaq = vec[pr+1]-vec[pr-1]-1;
			if(valaq == maxi && !pulou){
				valaq =  (valaq-1)/2;
				pulou = true;
			} 
			minew = min(minew, valaq);
		}
		else if(i == pr+1 && pr == 0){
			int valaq = vec[pr+1]-1;
			if((maxi-1)/2 <= valaq-1 && !pulou){
				// valaq =  (valaq-1)/2;
				// if( i == 0)
					valaq--;
				// else
					// valaq=(valaq-1)/2;
				pulou = true;
			} 
			minew = min(minew, valaq);
		}
		else{
			int valaq = mimimi[i];
			if(valaq == maxi && !pulou){
				if(i == 0)
					valaq--;
				else
					valaq =  (valaq-1)/2;
				pulou = true;
			}
			minew = min(minew, valaq);
		}
	}


	return minew;
	// if(maxi < 2*minew+1)
	// 	return -INF;
	// else
	// 	return minew;
}

int main() { _
	int t;
	cin >> t;
	while(t--) {

		cin >> n >> d;
		vector<int> vec(n);// 1-based
		for(int &i : vec) cin >> i;

		//espaco vazio antes do i-esimo
		vector<int> mimimi(n);
		mimimi[0] = vec[0]-1;
		int mini = mimimi[0];
		for(int i = 1; i < n; i++){
			mimimi[i] = vec[i]-vec[i-1]-1;
			mini = min(mini,mimimi[i]);
		}

		vector<int> mis;// 0-based
		for(int i = 0; i < n; i++) {
			if(mimimi[i] == mini)
				mis.push_back(i);
		}
		assert(mis.size() > 0);
		if(mis.size() > 2)
			cout << mini << endl;
		else {
			int duml =  d - vec[n-1];
			int ans = mini;
			for(int mip : mis) {
				int minew = tiraeve(mip,mimimi,vec,duml, mini);
				ans = max(minew, ans);
				if(mip < n-1)
				minew = tiraeve(mip+1,mimimi,vec,duml, mini);
				ans = max(minew, ans);
				if(mip > 0)
				minew = tiraeve(mip-1,mimimi,vec,duml, mini);
				ans = max(minew, ans);
			}
			cout << ans << endl;
		}
	}
	exit(0);
}


/*
1
2 5
1 5

1
*/