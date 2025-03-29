#include <iostream>
#include <vector>
#include <limits>
using namespace std;
 
using ll = long long;
const ll INF = 1e18;
struct Line {
    ll m, b;
    ll eval(ll x) const { return m * x + b; }
};
 
struct ConvexHull {
    vector<Line> hull;
    int pointer = 0;
 
    bool bad(const Line& l1, const Line& l2, const Line& l3) {
        return (l3.b - l1.b) * (l1.m - l2.m) <= (l2.b - l1.b) * (l1.m - l3.m);
    }
 
    void add(Line l) {
        while (hull.size() >= 2 && bad(hull[hull.size()-2], hull[hull.size()-1], l))
            hull.pop_back();
        hull.push_back(l);
    }
 
    ll query(ll x) {
        if (hull.empty()) return INF;
        while (pointer + 1 < (int)hull.size() && hull[pointer].eval(x) > hull[pointer+1].eval(x))
            pointer++;
        return hull[pointer].eval(x);
    }
 
    void resetPointer() { pointer = 0; }
};
 
class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size();
        vector<int> cavolinexy = nums;  
        
        vector<ll> P(n+1, 0), Q(n+1, 0);
        for (int i = 0; i < n; i++) {
            P[i+1] = P[i] + nums[i];
            Q[i+1] = Q[i] + cost[i];
        }
 
        vector<ll> dp_prev(n+1, INF), dp_curr(n+1, INF);
        dp_prev[0] = 0;  
 
        ll ans = INF;
        for (int p = 1; p <= n; p++) {
            ConvexHull cht;
            for (int j = 0; j <= n; j++) dp_curr[j] = INF;
            cht.hull.clear();
            cht.resetPointer();
 
            for (int i = p-1; i < n; i++) {
                Line l;
                l.m = -Q[i];
                l.b = dp_prev[i];
                cht.add(l);
            }
            for (int j = p; j <= n; j++) {
                ll x = P[j] + (ll)k * p;
                ll best = cht.query(x);
                dp_curr[j] = x * Q[j] + best;
            }
            if (dp_curr[n] < ans) ans = dp_curr[n];
            dp_prev = dp_curr;
        }
 
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums1 = {3, 1, 4};
    vector<int> cost1 = {4, 6, 6};
    int k1 = 1;
    Solution sol;
    cout << "Example 1 output: " << sol.minimumCost(nums1, cost1, k1) << "\n"; 

    vector<int> nums2 = {4,8,5,1,14,2,2,12,1};
    vector<int> cost2 = {7,2,8,4,2,2,1,1,2};
    int k2 = 7;
    cout << "Example 2 output: " << sol.minimumCost(nums2, cost2, k2) << "\n";  
 
    return 0;
}
