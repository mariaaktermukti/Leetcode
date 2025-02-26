#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        size_t pos = haystack.find(needle);
        return (pos != std::string::npos) ? pos : -1;
    }
};

int main() {
    Solution sol;
    
    std::string haystack1 = "sadbutsad", needle1 = "sad";
    std::cout << "Output: " << sol.strStr(haystack1, needle1) << std::endl; 

    std::string haystack2 = "leetcode", needle2 = "leeto";
    std::cout << "Output: " << sol.strStr(haystack2, needle2) << std::endl; 
    
    return 0;
}
