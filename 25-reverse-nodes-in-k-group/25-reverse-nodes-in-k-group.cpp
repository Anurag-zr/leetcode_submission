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
    
    ListNode* reverse(ListNode* first,ListNode* last){
        ListNode* prev= last;
        ListNode* cur= first;
        ListNode* temp;
        
        while(cur!=last){
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL || k==1) return head;
        
             ListNode *node = head;

        for (int i = 0; i < k;i++){
            if(node==NULL)
                return head; // too short list k group

                node=node->next;
        }

        ListNode *newHead = reverse(head, node); // first and last till then we have to reverse
        head->next = reverseKGroup(head->next, k);

        return newHead;   
    }
};