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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* cur = head;
        
        while(cur!=NULL){
            if(cur->val  == val){
                prev->next = cur->next;
                cur=cur->next;
            }
            else{
            cur=cur->next;
            prev=prev->next;
            }
        }
        
        return dummy->next;
    }
};