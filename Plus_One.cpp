#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) 
{
    int n = digits.size();
    
    for (int i = n - 1; i >= 0; --i) 
    {
        digits[i]++;
        if (digits[i] < 10) 
        {
            return digits;
        }
        digits[i] = 0;
    }

    digits.insert(digits.begin(), 1);
    return digits;
}

int main() 
{
    int n;
    cout << "Enter the number of digits: ";
    cin >> n;

    vector<int> digits(n);
    cout << "Enter the digits (space separated): ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> digits[i];
    }

    vector<int> result = plusOne(digits);

    cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) 
    {
        cout << result[i];
        if (i != result.size() - 1) 
        {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
