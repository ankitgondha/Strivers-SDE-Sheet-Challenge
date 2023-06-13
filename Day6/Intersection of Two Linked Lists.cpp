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
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        ListNode *q = new ListNode(0);

        while(tempA != NULL){
            tempB = headB;
            while(tempB != NULL){

                if(tempA == tempB){
                    return tempB;
                }
                tempB = tempB -> next;
            }
            tempA = tempA -> next;
        }
        return nullptr;
    }
};