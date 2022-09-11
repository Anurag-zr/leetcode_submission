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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head ==NULL) return head;
        
        ListNode* cur=head;
        ListNode* temp = cur;
        
        
        while(cur->next!=NULL){
            while(temp!=NULL && cur->val==temp->val){
                temp=temp->next;
            }
            
            if(temp==NULL) cur->next=temp;
            else{
               cur->next = temp;
                cur=temp;
            }
        }
        
        return head;
    }
};