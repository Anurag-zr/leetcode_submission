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
    ListNode* deleteMiddle(ListNode* head) {
      ListNode* dummy = new ListNode(0);
        ListNode *slow,*fast;
        dummy->next = head;
        slow = fast =dummy;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            // cout<<slow->val<<fast->val<<endl;
            fast = fast->next->next;
            slow = slow->next;
        }
        
//         if(fast->next==NULL){//odd no of nodes exist
//             slow->next = slow->next->next;
//         }
        
//         if(fast->next->next == NULL){
            
//         }
        
        slow ->next = slow->next->next;
        
        
        return dummy->next;
        
    }
};