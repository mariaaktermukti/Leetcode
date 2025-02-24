#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
{
    sort(products.begin(), products.end());

    vector<vector<string>> result;
    string prefix = "";
    for (char c : searchWord) 
    {
        prefix += c; 
        vector<string> suggestions;
        for (string& product : products) 
        {
            if (product.find(prefix) == 0) 
            {
                suggestions.push_back(product);
                if (suggestions.size() == 3) break; 
            }
        }
        result.push_back(suggestions);
    }

    return result;
};

int main() 
{
    int n;
    cout << "Enter the number of products: ";
    cin >> n;

    vector<string> products(n);
    cout << "Enter the products: ";
    for (int i = 0; i < n; ++i) {
        cin >> products[i];
    }

    string searchWord;
    cout << "Enter the search word: ";
    cin >> searchWord;

    vector<vector<string>> result = suggestedProducts(products, searchWord);

    cout << "Suggested products after each character:" << endl;
    for (int i = 0; i < result.size(); ++i) 
    {
        cout << "After typing '" << searchWord.substr(0, i + 1) << "': [";
        for (int j = 0; j < result[i].size(); ++j) 
        {
            cout << result[i][j];
            if (j != result[i].size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
