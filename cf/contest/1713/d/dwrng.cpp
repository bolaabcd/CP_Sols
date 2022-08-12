#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
// CPP program for implementation of QuickSelect
 
int arrr[int(1e6)];
int meq (int l, int r) {
	if(l == r)
		return 0;
	cout << "? " << l << ' ' << r << endl;
	int x;
	cin >> x;
	return x;
}

// Standard partition process of QuickSort().
// It considers the last element as pivot
// and moves all smaller element to left of
// it and greater elements to right
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (meq(arr[j], x) != 1) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
  
// This function returns k'th smallest 
// element in arr[l..r] using QuickSort 
// based method.  ASSUMPTION: ALL ELEMENTS
// IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of 
    // elements in array
    if (k > 0 && k <= r - l + 1) {
  
        // Partition the array around last 
        // element and get position of pivot 
        // element in sorted array
        int index = partition(arr, l, r);
  
        // If position is same as k
        if (index - l == k - 1)
            return arr[index];
  
        // If position is more, recur 
        // for left subarray
        if (index - l > k - 1) 
            return kthSmallest(arr, l, index - 1, k);
  
        // Else recur for right subarray
        return kthSmallest(arr, index + 1, r, 
                            k - index + l - 1);
    }
  
    // If k is more than number of 
    // elements in array
    return INT_MAX;
}

  
void solve() {
	int n,dn = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		dn *=2;
	if(n == 1) {
		cout << "! 1" << endl;
		return;
	} else if (n == 2) {
		cout << "? 1 2" << endl;
		int x;
		cin >> x;
		if(x == 1)
			cout << "! 1" << endl;
		else
			cout << "! 2" << endl;
		return;
	}
	for(int i = 0; i < dn; i++)
		arrr[i] = i+1;
	int ans = kthSmallest(arrr,0,dn-1,dn) ;
	cout << "! " << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)solve();
	exit(0);
}
