#include<iostream>
#include<vector>
#include "../ListNode.h"
using namespace std;
class Problem234{
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr){
            return true;
        }
        if(head->next->next ==nullptr ){
            if(head->val == head->next->val)
                return true;
            else{
                return false;
            }
        }
        ListNode* prevOfMiddle = findMiddle(head);
        ListNode* middle = prevOfMiddle->next;
        prevOfMiddle->next = nullptr;
        ListNode* prevNode = nullptr;
        ListNode* currNode = middle;
        ListNode* nextNode = nullptr;

        // Reverse the second half of the list
        while (currNode != nullptr) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
         
        currNode = prevNode;

        while(head!=nullptr && currNode!=nullptr){
            
           
            if(head->val!=currNode->val){
                
                return false;
            }
            head = head->next;
            currNode = currNode->next;
        }
        return true;


    }
    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head->next->next;
        ListNode* middle = head->next;
        ListNode* prevOfMiddle = head;
        while(fast!=nullptr){
            if(fast->next==nullptr)
                return middle;
            fast=fast->next->next;
            prevOfMiddle = middle;
            middle = middle->next;      
        }
        return prevOfMiddle;
    }
};
int main(){
    vector<int> vec = {1,0,1};
    ListNode* head1 = ListNode::createLinkedList(vec);
    Problem234 problem234;
    cout<<problem234.isPalindrome(head1)<<"\n";
}