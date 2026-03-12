#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    int min_cakes = Y / X;
    int total_vehicles = ceil((double)N / min_cakes);
    cout << total_vehicles << endl;
}