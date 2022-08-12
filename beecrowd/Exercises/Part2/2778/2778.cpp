#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const short MAX = 100;

short n,m,xt,yt;

short mat[MAX][MAX];
int memo[MAX][MAX][21][21][3];

// line, col, remaining x, remaining y, option {'l' if can only go left, 'b' if both, 'r' if only right}
int dp(short l, short c, short x, short y,char op) {
	// Trying to move out of the matrix is invalid
	if(l < 0 || l >= n)
		return INF;
	if(c < 0 || c >= m)
		return INF;

	// valid options
	assert(op == 'l' || op == 'r' || op == 'b');
	char opmemo;
	if(op == 'l')
		opmemo = 0;
	else if(op == 'b')
		opmemo = 1;
	else
		opmemo = 2;

	// Using stored result (It's the same if we move down-left or left-down, for example)
	if(memo[l][c][x][y][opmemo] != -1)
		return memo[l][c][x][y][opmemo];

	// We set xn and yn as how much non-positive we can still get after passing through this one.
	short xn = x, yn = y;
	if(mat[l][c] == 0)
		xn--;
	else if(mat[l][c] < 0)
		yn--;

	// If this is the (x+1)th null or (y+1)th negative, we have a problem.
	if(xn < 0)
		return memo[l][c][x][y][opmemo] = INF;
	if(yn < 0)
		return memo[l][c][x][y][opmemo] = INF;
	
	// Base case: we got to the end sucessfully!
	if(l == n-1 && c == m-1)
		return memo[l][c][x][y][opmemo] = mat[l][c];


	int ans = INF;
	// If we don't need to go left necessarily, go right
	if (op != 'l')
		ans = min(ans,dp(l,c+1,xn,yn,'r'));
	// if we don't need to go right necessarily, go left
	if (op != 'r')
		ans = min(ans,dp(l,c-1,xn,yn,'l'));
	// anyway, try to go down because no one will ever try to stop you (maybe the floor)
	ans = min(ans,dp(l+1,c,xn,yn,'b'));

	if(op == 'l')
		assert(opmemo == 0);
	// If we found a problem, report it with the same value, so we identify problems easily later
	if(ans == INF)
		return memo[l][c][x][y][opmemo] = INF;
// If we don't have a problem, then we must add the current node value to the best possible way after it
	else
		return memo[l][c][x][y][opmemo] = ans+mat[l][c];
}


// Number of test cases is 20, found by binary search
int main() { _
	int ntestcases = 0;
	while(1) {
		ntestcases++;
		cin >> n >> m >> xt >> yt;
		if(cin.eof())
			break;
		// I don't trust beecrowd...
		assert(xt >= 0);
		assert(yt >= 0);
		assert(xt <= 20);
		assert(yt <= 20);
		assert(n >= 1);
		assert(m >= 1);
		assert(n <= 100);
		assert(m <= 100);
		assert(ntestcases <= 20);
		for(short i = 0; i < n; i++)
			for(short j = 0; j < m; j++){
				cin >> mat[i][j];
				assert(mat[i][j] >= -100);
				assert(mat[i][j] <=  100);
			}
		memset(memo,-1,sizeof(memo));
		int ans = dp(0,0,xt,yt,'b');
		if(ans == INF)
			cout << "Impossivel" << endl;
		else
			cout << ans << endl;
	}
	exit(0);
}

// Manual bynary search results:
// More than 7 test cases
// More than 19 test cases
// 49 or less test cases         //// my checking condition was not correct up to this point
// 30 or less test cases
// 25 or less test cases
// 20 or less test cases
// More than 19 test cases