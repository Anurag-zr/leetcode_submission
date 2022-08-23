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
            
        ListNode *newHead =NULL;
        ListNode *temp;
        
        while(head!=NULL){   //linked list structure got reversed while executing this code
            temp=head->next;
            s+=(head->val+'0');
            head->next=newHead;
            newHead=head;
            head=temp;
        }
        
        
        //linked list structure again got reversed after following code execution
        //retreving the original linked list structure again.
        head = NULL;  
        while(newHead!=NULL){  
            temp=newHead->next;
            revs+=(newHead->val + '0');
            newHead->next=head;
            head=newHead;
            newHead=temp;
        }
        
        if(s==revs) return true;
        return false;
    }
};