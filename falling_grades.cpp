#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t; 
    cin >> t;

    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> my_vec(n);
        int sum = 0;
        bool everBelow40 = false; 
        for (int i = 0; i < n; i++) 
        {
            cin >> my_vec[i];
            sum += my_vec[i];

            double avg_total = (double)sum / (i + 1);
            if (avg_total < 40) 
            {
                everBelow40 = true;
            }
        }
        double final_avg = (double)sum / n;
        if (final_avg >= 40 && !everBelow40) 
        {
            cout << "Yes" << endl;
        } 
        else 
        {
            cout << "No" << endl;
        }
    }

    return 0;
}