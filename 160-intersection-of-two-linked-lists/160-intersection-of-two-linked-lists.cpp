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
        ListNode *dummyA, *dummyB;
        dummyA = headA;
        dummyB = headB;

        while(dummyA!=dummyB){
            dummyA = dummyA == NULL ? headB : dummyA->next;
            dummyB = dummyB == NULL ? headA : dummyB->next;
        }

        return dummyA;
    }
};