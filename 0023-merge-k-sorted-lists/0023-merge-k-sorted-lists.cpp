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
    struct comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val >
                   b->val; 
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        int n = lists.size();
        for (int i = 0; i < n; i++) {
            ListNode* curr= lists[i];
            while(curr!= NULL){
                pq.push(curr);
                curr=curr->next;
            }
        }

        ListNode* temp= new ListNode();
        ListNode* curr= temp;
        while(!pq.empty()){
            curr->next=pq.top();
            pq.pop();
            curr=curr->next;
        }
curr->next = nullptr; // Ensure last node points to null
        return temp->next;
    }
};