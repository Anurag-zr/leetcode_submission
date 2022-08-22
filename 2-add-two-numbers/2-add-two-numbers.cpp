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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode;
        ListNode *temp = dummy;
        
        int sum=0;
        int carry=0;
        
        while(l1!=NULL || l2!=NULL || carry!=0){
            ListNode *newNode = new ListNode;
          if(l1!=NULL && l2!=NULL){
               sum = l1->val+l2->val+carry;
               newNode->val = sum%10;
               carry = sum/10;
               temp->next=newNode;
               temp=temp->next;
              l1=l1->next;
              l2=l2->next;
          }  
            
          else if(l1==NULL && l2!=NULL){
               sum = l2->val+carry;
               newNode->val = sum%10;
               carry = sum/10;
               temp->next=newNode;
               temp=temp->next;
              l2=l2->next;
           }
            
          else if(l2==NULL && l1!=NULL){
               sum = l1->val+carry;
               newNode->val = sum%10;
               carry = sum/10;
               temp->next=newNode;
               temp=temp->next;
              l1=l1->next;
           }
            
          else{
              sum= carry;
              newNode->val = sum%10;
              carry=sum/10;
              temp->next = newNode;
              temp=temp->next;
          }
            
           
        }
        
        return dummy->next;
    }
};