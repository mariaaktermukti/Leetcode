#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int components = 0;
        bool inComponent = false;

        while (head != nullptr) {
            if (numSet.count(head->val)) 
            {
                if (!inComponent)
                {
                    components++;
                    inComponent = true;
                }
            } 
            else
             {
                inComponent = false;
            }
            head = head->next;
        }

        return components;
    }
};

ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    vector<int> listValues = {0, 1, 2, 3};
    vector<int> nums = {0, 1, 3};

    ListNode* head = createLinkedList(listValues);

    Solution solution;
    int result = solution.numComponents(head, nums);

    printf("Number of connected components: %d\n", result);
    deleteLinkedList(head);

    return 0;
}
