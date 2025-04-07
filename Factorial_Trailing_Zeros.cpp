#include <iostream>
using namespace std;

int trailingZeroes(int n) 
{
    int count = 0;
    while (n >= 5) 
    {
        n /= 5;
        count += n;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = trailingZeroes(n);
    cout << "Number of trailing zeroes in " << n << "! is: " << result << endl;

    return 0;
}
