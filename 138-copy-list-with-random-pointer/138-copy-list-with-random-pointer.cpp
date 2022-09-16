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
        if(head==NULL) return NULL;
        
        Node* itr = head;
        
        while(itr!=NULL){
            Node* newNode = new Node(itr->val);
            newNode->next = itr->next;
            itr->next = newNode;
            itr=itr->next->next;
        }
        
        itr = head;
        
        while(itr!=NULL){
           if(itr->random!=NULL) itr->next->random = itr->random->next;
            else itr->next->random = itr->random;
            itr=itr->next->next;
        }
        
        Node* newl = head->next;
        Node* newHead = newl;
        Node* oldl = head;
        
        while(newl->next!=NULL){
            oldl->next = newl->next;
            newl->next = oldl->next->next;
            oldl=oldl->next;
            newl=newl->next;
        }
        
        oldl->next = newl->next;
        
        
        
        
        
        
        return newHead;
    }
};