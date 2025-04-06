#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    ListNode* a = headA;
    ListNode* b = headB;

    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }

    return a; 
}

ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int sizeA, sizeB, skipA, skipB;
    cout << "Enter size of list A: ";
    cin >> sizeA;
    cout << "Enter size of list B: ";
    cin >> sizeB;

    cout << "Enter skipA (nodes before intersection in A): ";
    cin >> skipA;
    cout << "Enter skipB (nodes before intersection in B): ";
    cin >> skipB;

    vector<int> valuesA(sizeA);
    vector<int> valuesB(sizeB);

    cout << "Enter values for list A: ";
    for (int i = 0; i < sizeA; ++i) cin >> valuesA[i];

    cout << "Enter values for list B: ";
    for (int i = 0; i < sizeB; ++i) cin >> valuesB[i];

    ListNode* headA = nullptr;
    ListNode* headB = nullptr;
    ListNode* currentA = nullptr;
    ListNode* currentB = nullptr;

    for (int i = 0; i < skipA; ++i) {
        ListNode* newNode = new ListNode(valuesA[i]);
        if (!headA) headA = currentA = newNode;
        else currentA = currentA->next = newNode;
    }

    for (int i = 0; i < skipB; ++i) {
        ListNode* newNode = new ListNode(valuesB[i]);
        if (!headB) headB = currentB = newNode;
        else currentB = currentB->next = newNode;
    }

    vector<int> intersectValues;
    for (int i = skipA; i < sizeA && i - skipA + skipB < sizeB; ++i) {
        if (valuesA[i] == valuesB[i - skipA + skipB]) {
            intersectValues.push_back(valuesA[i]);
        } else break;
    }

    ListNode* intersect = createList(intersectValues);

    if (currentA) currentA->next = intersect;
    else headA = intersect;

    if (currentB) currentB->next = intersect;
    else headB = intersect;

    ListNode* result = getIntersectionNode(headA, headB);

    if (result) {
        cout << "Intersected at '" << result->val << "'" << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}
