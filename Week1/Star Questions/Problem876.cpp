#include<iostream>
#include<vector>

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

