#include<iostream>
#include<vector>
#include "../ListNode.h"
using namespace std;
class Problem876{
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next == nullptr){
            return head;
        }
        if(head->next->next == nullptr){
            return head->next;
        }
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while(fast != nullptr){
            if(fast == slow || fast->next == nullptr){
                return slow;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
int main(){
        vector<int> values = {1, 2, 3, 4, 5};

    // Create a linked list from the vector
    ListNode* head = ListNode::createLinkedList(values);
    Problem876 problem;
    ListNode* middle = problem.middleNode(head);
    cout<<middle->val<<"\n";
}
