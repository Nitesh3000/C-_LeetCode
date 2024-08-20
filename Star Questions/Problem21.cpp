#include<iostream>
#include<vector>
#include "../ListNode.h"
using namespace std;
class Problem21{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;
        
        while(list1!=NULL && list2!=NULL){
            ListNode* newnode = new ListNode();
            if(list1->val >= list2->val){
                newnode->val = list2->val;
                list2 = list2->next;
            }
            else{
                newnode->val = list1->val;
                list1 = list1->next;
            }
            temp->next = newnode;
            temp = newnode;
        }
        if(list1 == NULL){
            while(list2 != NULL){
                ListNode* newnode = new ListNode();
                newnode->val = list2->val;
                list2 = list2->next;
                temp->next = newnode;
                temp = temp->next;
            }
        }
        else{
          while(list1 != NULL){
                ListNode* newnode = new ListNode();
                newnode->val = list1->val;
                list1 = list1->next;
                temp->next = newnode;
                temp = temp->next;
            }  
        }
        return head->next;
    }
};
int main(){
    vector<int> values1 = {1, 2, 3, 4, 5};

    // Create a linked list from the vector
    ListNode* head1 = ListNode::createLinkedList(values1);

    
    vector<int> values2 = {1, 2, 3, 4, 5};

    // Create a linked list from the vector
    ListNode* head2 = ListNode::createLinkedList(values1);



    Problem21 problem21;
    ListNode* head3 = problem21.mergeTwoLists(head1,head2);
    ListNode* current = head3;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    cout<<"\n";

}