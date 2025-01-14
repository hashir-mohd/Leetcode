/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mpp;
        Node* curr= head;
        while(curr!=NULL){
            Node* temp= new Node(curr->val);
            mpp[curr]=temp;
            curr=curr->next;
        }

        curr=head;
        while(curr!=NULL){
            Node* copy= mpp[curr];
            copy->next= mpp[curr->next];
            copy->random= mpp[curr->random];
            curr=curr->next;
        }
        return mpp[head];
    }
};