#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
const int MAXN = 200005;

int tree_cnt[4 * MAXN];
ll tree_sum[4 * MAXN];
int N_map;
vector<int> rank_to_val;

void clear_tree(int n)
{
    for (int i = 0; i <= 4 * n; ++i)
    {
        tree_cnt[i] = 0;
        tree_sum[i] = 0;
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        tree_cnt[node]++;
        tree_sum[node] += val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
        update(2 * node, start, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, end, idx, val);

    tree_cnt[node] = tree_cnt[2 * node] + tree_cnt[2 * node + 1];
    tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
}

int get_kth_val(int node, int start, int end, int k)
{
    if (start == end)
        return rank_to_val[start];
    int mid = (start + end) / 2;
    if (k < tree_cnt[2 * node])
        return get_kth_val(2 * node, start, mid, k);
    else
        return get_kth_val(2 * node + 1, mid + 1, end, k - tree_cnt[2 * node]);
}

ll get_sum_smallest(int node, int start, int end, int k)
{
    if (k <= 0)
        return 0;
    if (k >= tree_cnt[node])
        return tree_sum[node];
    if (start == end)
        return (ll)k * rank_to_val[start];
    int mid = (start + end) / 2;
    if (tree_cnt[2 * node] >= k)
        return get_sum_smallest(2 * node, start, mid, k);
    else
        return tree_sum[2 * node] + get_sum_smallest(2 * node + 1, mid + 1, end, k - tree_cnt[2 * node]);
}

void solve()
{
    int N;
    if (!(cin >> N))
        return;
    vector<int> A(N);
    vector<int> vals;
    vals.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        vals.push_back(A[i]);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    rank_to_val = vals;
    N_map = vals.size();

    clear_tree(N_map);

    int cur_max = -2e9 - 7;
    int cur_min = 2e9 + 7;
    ll total_sum = 0;

    for (int i = 1; i <= N; ++i)
    {
        int val = A[i - 1];
        int rk = lower_bound(vals.begin(), vals.end(), val) - vals.begin();
        update(1, 0, N_map - 1, rk, val);

        if (val > cur_max)
            cur_max = val;
        if (val < cur_min)
            cur_min = val;
        total_sum += val;

        if (i == 1)
        {
            cout << 0 << (i == N ? "" : " ");
            continue;
        }

        ll ans = 0;

        int low = 0, high = i - 1;
        int best_k1 = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (mid == i - 1)
            {
                best_k1 = max(best_k1, mid);
                low = mid + 1;
                continue;
            }

            ll s_k = get_sum_smallest(1, 0, N_map - 1, mid);
            ll v_next = get_kth_val(1, 0, N_map - 1, mid);

            if (v_next * (ll)(mid + 1) < (ll)cur_max + s_k)
            {
                best_k1 = mid + 1;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        ll sum_k1 = get_sum_smallest(1, 0, N_map - 1, best_k1);
        ll avg1 = ((ll)cur_max + sum_k1) / (best_k1 + 1);
        ans = max(ans, abs((ll)cur_max - avg1));

        low = 0;
        high = i - 1;
        int best_k2 = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (mid == i - 1)
            {
                best_k2 = max(best_k2, mid);
                low = mid + 1;
                continue;
            }

            ll s_k = total_sum - get_sum_smallest(1, 0, N_map - 1, i - mid);

            ll v_next = get_kth_val(1, 0, N_map - 1, i - 1 - mid);

            if (v_next * (ll)(mid + 1) > (ll)cur_min + s_k)
            {
                best_k2 = mid + 1;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        ll sum_k2 = total_sum - get_sum_smallest(1, 0, N_map - 1, i - best_k2);
        ll avg2 = ((ll)cur_min + sum_k2) / (best_k2 + 1);
        ans = max(ans, abs(avg2 - (ll)cur_min));

        cout << ans << (i == N ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    int T;
    if (cin >> T)
    {
        while (T--)
        {
            solve();
        }
    }
    return 0;
}