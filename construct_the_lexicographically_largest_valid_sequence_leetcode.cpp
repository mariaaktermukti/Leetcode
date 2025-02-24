#include <iostream>
#include <vector>

using namespace std;

bool constructSequence(vector<int>& result, vector<bool>& used, int n, int pos) 
{
    if (pos == result.size()) 
    {
        return true;
    }
    
    if (result[pos] != 0) 
    {
        return constructSequence(result, used, n, pos + 1);
    }
    
    for (int i = n; i >= 1; --i) 
    {
        if (!used[i]) 
        {
            used[i] = true;
            result[pos] = i;

            if (i == 1) 
            {
                if (constructSequence(result, used, n, pos + 1)) 
                {
                    return true;
                }
            } 
            else if (pos + i < result.size() && result[pos + i] == 0) 
            {
                result[pos + i] = i;
                if (constructSequence(result, used, n, pos + 1)) 
                {
                    return true;
                }
                result[pos + i] = 0;
            }
            
            result[pos] = 0;
            used[i] = false;
        }
    }
    
    return false;
}

vector<int> constructDistancedSequence(int n) 
{
    vector<int> result(2 * n - 1, 0);
    vector<bool> used(n + 1, false);
    constructSequence(result, used, n, 0);
    return result;
}

int main() 
{
    int n;
    cin >> n;
    
    vector<int> result = constructDistancedSequence(n);
    
    for (int num : result) 
    {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
