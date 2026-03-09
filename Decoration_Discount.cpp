#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	while(t--)
    {
	    int n;
	    cin >> n;
	    vector<int> arr(n);
	    for(int i = 0; i < n; i++) cin >> arr[i];

	    int mn = INT_MAX;
	    for(int i = 0; i < n - 1; i++) 
        {
	        mn = min(mn, arr[i] + arr[i+1] / 2);
	    }
	    int m1 = *min_element(arr.begin(), arr.end());

	    auto it = find(arr.begin(), arr.end(), m1);
	    if (it != arr.end()) arr.erase(it);

	    int m2 = *min_element(arr.begin(), arr.end());

	    mn = min(mn, m1 + m2);

	    cout << mn << endl;
	}
}
