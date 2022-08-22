/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     
        unordered_map<ListNode*,bool> umap;
        ListNode* temp=headA;
        while(temp!=NULL){
            umap[temp]=true;
            temp=temp->next;
        }
        
        
        temp= headB;
        
        while(temp!=NULL){
            if(umap.find(temp)!=umap.end()) return temp;
            temp=temp->next;
        }
        
        return NULL;
    }
};