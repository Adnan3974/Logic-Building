#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        
        return dummy->next;
    }
};

class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (head != nullptr && head->next != nullptr) {
            ListNode* first = head;
            ListNode* second = head->next;
            
            prev->next = second;
            first->next = second->next;
            second->next = first;
            prev = first;
            head = first->next;
        }
        
        return dummy->next;
    }
};
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

void printList(ListNode* head) {
    cout << "[";
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) {
            cout << ",";
        }
        head = head->next;
    }
    cout << "]" << endl;
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    cout << "=== Add Two Numbers ===" << endl;
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);
    
    Solution1 s1;
    ListNode* result1 = s1.addTwoNumbers(l1, l2);
    
    cout << "Input: L1 = ";
    printList(l1);
    cout << "Input: L2 = ";
    printList(l2);
    cout << "Output: ";
    printList(result1);
    cout << endl;
    deleteList(l1);
    deleteList(l2);
    deleteList(result1);
    
    int arr3[] = {0};
    int arr4[] = {0};
    ListNode* l3 = createList(arr3, 1);
    ListNode* l4 = createList(arr4, 1);
    
    ListNode* result2 = s1.addTwoNumbers(l3, l4);
    
    cout << "Input: L1 = ";
    printList(l3);
    cout << "Input: L2 = ";
    printList(l4);
    cout << "Output data: ";
    printList(result2);
    cout << endl;
    
    deleteList(l3);
    deleteList(l4);
    deleteList(result2);
    
    cout << "Swapping Two Nodes" << endl;
    
    int arr5[] = {1, 2, 3, 4};
    ListNode* head1 = createList(arr5, 4);
    
    Solution2 s2;
    ListNode* result3 = s2.swapPairs(head1);
    
    cout << "Input data: ";
    printList(head1);
    cout << "Output data: ";
    printList(result3);
    cout << endl;
    
    deleteList(result3);
    
    ListNode* head2 = nullptr;
    ListNode* result4 = s2.swapPairs(head2);
    
    cout << "Input: ";
    printList(head2);
    cout << "Output: ";
    printList(result4);
    cout << endl;
    
    int arr6[] = {1};
    ListNode* head3 = createList(arr6, 1);
    ListNode* result5 = s2.swapPairs(head3);
    
    cout << "Input: ";
    printList(head3);
    cout << "Output: ";
    printList(result5);
    cout << endl;
    
    deleteList(result5);
    int arr7[] = {1, 2, 3};
    ListNode* head4 = createList(arr7, 3);
    ListNode* result6 = s2.swapPairs(head4);
    
    cout << "Input: ";
    printList(head4);
    cout << "Output: ";
    printList(result6);
    cout << endl;
    
    deleteList(result6);
    
    return 0;
}
