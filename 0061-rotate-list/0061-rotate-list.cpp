/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int count =1 ;
        ListNode* curr=head;
        while(curr->next != NULL){
            curr=curr->next;
            count++;
        }
        
        k%=count;
        ListNode* slow=head;
        ListNode* fast=head;
        while(k>=0){
            fast=fast->next;
            k--;
        }
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;

        }
        curr->next= head;
        ListNode* temp= slow->next;
        slow->next= NULL;
        return temp;


    }
};