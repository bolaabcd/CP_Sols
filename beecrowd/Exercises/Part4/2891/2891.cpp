#include <iostream>
#include <cassert>

using namespace std;

int x[5], y[5];

int A(int i, int j, int k) {
	int ans = abs((x[j] - x[i])*(y[k]-y[j])-(x[k]-x[j])*(y[j]-y[i]));
	assert(ans %2 == 0);
	return ans/2;
}

void solve () {
	int maxi = -0x3f3f3f3f;
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			if(j != i)
				for(int k = 0; k < 5; k++)
					if(k != j && k != i)
						for(int l = 0; l < 5; l++)
							if(l != k && l != j && l != i)
								if(A(i,j,k) + A(i,j,l) == A(k,l,i) + A(k,l,j))
									maxi = max(maxi,A(i,j,k) + A(i,j,l));
	cout << maxi << endl;
}
int main() {
	while(1) {
		for(int i = 0; i < 5; i++)
			cin >> x[i] >> y[i];
		if(x[0] == 0 && y[0] == 0 && x[1] == 0 && y[1] == 0 && x[2] == 0 && y[2] == 0)
			break;
			solve();
	}
	
	return 0;
}
