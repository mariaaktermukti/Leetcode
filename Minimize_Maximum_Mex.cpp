#include <bits/stdc++.h>
using namespace std;

int solve(int n, const vector<int> &a, const vector<int> &b)
{
  map<int, int> freq;
  map<int, bool> has_double_pair;

  for (int i = 0; i < n; ++i) 
  {
    freq[a[i]]++;
    freq[b[i]]++;
    if (a[i] == b[i]) 
    {
      has_double_pair[a[i]] = true;
    }
  }

  int max_key = 0;
  if (!freq.empty()) 
  {
    max_key = freq.rbegin()->first;
  }

  int unpaired_values = 0;
  for (int val = 0; val <= max_key + 1; ++val) 
  {
    if (freq.find(val) == freq.end()) break;

    if (!has_double_pair[val]) 
    {
      unpaired_values++;
      if (unpaired_values == 2) 
      {
        return val;
      }
    }
  }
  int mex = 0;
  while (freq.find(mex) != freq.end()) 
  {
    mex++;
  }
  return mex;
}

int main() 
{
  int t;
  cin >> t;
  while (t--) 
  {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int &x : A) cin >> x;
    for (int &x : B) cin >> x;

    cout << solve(N, A, B) << endl;
  }

  return 0;
}