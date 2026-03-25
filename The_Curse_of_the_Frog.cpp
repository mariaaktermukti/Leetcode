#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll jumpTypes, target;
        cin >> jumpTypes >> target;

        ll baseReach = 0;
        ll bestNetGain = LLONG_MIN;

        for (ll i = 0; i < jumpTypes; ++i)
        {
            ll jumpLength, interval, penalty;
            cin >> jumpLength >> interval >> penalty;

            baseReach += (interval - 1) * jumpLength;

            ll netGain = jumpLength * interval - penalty;
            bestNetGain = max(bestNetGain, netGain);
        }

        if (target <= baseReach)
        {
            cout << 0 << endl;
        }
        else if (bestNetGain <= 0)
        {
            cout << -1 << endl;
        }
        else
        {
            ll remaining = target - baseReach;
            ll minRollbacks = (remaining + bestNetGain - 1) / bestNetGain;
            cout << minRollbacks << endl;
        }
    }

    return 0;
}
