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
    bool isPalindrome(ListNode* head) {
        string s="";
        string revs="";
            
        ListNode *dummy =NULL;
        ListNode *temp;
        
        while(head!=NULL){
            temp=head->next;
            s+=(head->val+'0');
            head->next=dummy;
            dummy=head;
            head=temp;
        }
        
        while(dummy!=NULL){
            revs+=(dummy->val + '0');
            dummy = dummy->next;
        }
        
        if(s==revs) return true;
        return false;
    }
};