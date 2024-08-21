#include<iostream>
#include<vector>
#include "../ListNode.h"
using namespace std;
class Problem141{
public:
    bool hasCycle(ListNode *head) {
        
        if(head == nullptr){
            return false;
        }
        if(head->next == nullptr){
            return false;
        }
        if(head->next->next == nullptr){
            return false;
        }
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while(fast!=nullptr){
            if(slow == fast){
                return true;
            }
            else{
                slow = slow->next;
                if(fast->next==nullptr)
                    return false;
                fast = fast->next->next;
            }
        }
        return false;
    }
};
ListNode* createLinkedListWithCycle(int arr[], int size, int pos) {
    if (size == 0) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* tail = head;
    ListNode* cycleNode = nullptr;
    
    if (pos == 0) {
        cycleNode = head;
    }
    
    for (int i = 1; i < size; i++) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
        if (i == pos) {
            cycleNode = tail;
        }
    }
    
    if (pos != -1) {
        tail->next = cycleNode;
    }
    
    return head;
}

int main() {
    // Example 1: head = [3,2,0,-4], pos = 1
    Problem141 problem141;
    int arr1[] = {3, 2, 0, -4};
    ListNode* head1 = createLinkedListWithCycle(arr1, 4, 1);
    cout << (problem141.hasCycle(head1) ? "true" : "false") << endl;  // Output: true
    
    // Example 2: head = [1,2], pos = 0
    int arr2[] = {1, 2};
    ListNode* head2 = createLinkedListWithCycle(arr2, 2, 0);
    cout << (problem141.hasCycle(head2) ? "true" : "false") << endl;  // Output: true
    
    // Example 3: head = [1], pos = -1
    int arr3[] = {1};
    ListNode* head3 = createLinkedListWithCycle(arr3, 1, -1);
    cout << (problem141.hasCycle(head3) ? "true" : "false") << endl;  // Output: false
    
    return 0;
}