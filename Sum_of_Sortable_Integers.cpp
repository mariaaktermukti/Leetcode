#include <bits/stdc++.h>
using namespace std;

bool kmp(const vector<int> &text, const vector<int> &pattern)
{
    int n = text.size();
    int m = pattern.size();

    vector<int> pi(m, 0);
    int j = 0;

    for (int i = 1; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = pi[j - 1];
        }

        if (pattern[i] == pattern[j])
        {
            j++;
        }

        pi[i] = j;
    }

    j = 0;

    for (int i = 0; i < n; i++)
    {
        while (j > 0 && text[i] != pattern[j])
        {
            j = pi[j - 1];
        }

        if (text[i] == pattern[j])
        {
            j++;
        }

        if (j == m)
        {
            return true;
        }
    }

    return false;
}

bool isRotation(const vector<int> &a, const vector<int> &b)
{
    vector<int> doubled = a;
    doubled.insert(doubled.end(), a.begin(), a.end());

    return kmp(doubled, b);
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> target = nums;
    sort(target.begin(), target.end());

    vector<int> divisors;

    for (int d = 1; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            divisors.push_back(d);

            if (d != n / d)
            {
                divisors.push_back(n / d);
            }
        }
    }

    int ans = 0;

    for (int k : divisors)
    {
        bool sortable = true;

        for (int left = 0; left < n; left += k)
        {
            vector<int> a(nums.begin() + left,
                          nums.begin() + left + k);

            vector<int> b(target.begin() + left,
                          target.begin() + left + k);

            if (!isRotation(a, b))
            {
                sortable = false;
                break;
            }
        }

        if (sortable)
        {
            ans += k;
        }
    }

    cout << ans << '\n';

    return 0;
}