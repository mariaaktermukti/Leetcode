#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n;
        cin >> n;

        unordered_map<int, vector<int>> layers;
        int big = -1;
        vector<int> path;

        for (int i = 0; i < n; ++i)
        {
            cout << "? " << (i + 1) << " " << n;
            for (int s = 1; s <= n; ++s)
                cout << " " << s;
            cout << "\n"
                 << flush;

            int ans;
            if (!(cin >> ans))
                return 0;
            if (ans == -1)
                return 0;

            layers[ans].push_back(i + 1);
            if (ans > big)
            {
                big = ans;
                path.clear();
                path.push_back(i + 1);
            }
        }

        for (int depth = big - 1; depth >= 1; --depth)
        {
            if (layers.find(depth) == layers.end())
                continue;
            for (int candidate : layers[depth])
            {
                int last = path.back();
                cout << "? " << last << " 2 " << last << " " << candidate << "\n"
                     << flush;

                int ans;
                if (!(cin >> ans))
                    return 0;
                if (ans == -1)
                    return 0;

                if (ans == 2)
                {
                    path.push_back(candidate);
                    break;
                }
            }
        }

        cout << "! " << path.size();
        for (int v : path)
            cout << " " << v;
        cout << "\n"
             << flush;
    }

    return 0;
}
