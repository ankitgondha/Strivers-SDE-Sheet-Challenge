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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head -> next;
        int node = INT_MIN;
        while(slow!=NULL && fast != NULL){
            if(slow == fast){
                node = slow -> val;
                break;
            }
            if(fast -> next!=nullptr){

            slow = slow -> next;
            fast = fast ->next -> next;
            }
            else{
                break;
            }
        }
        if(slow == NULL || fast ==NULL || fast->next ==NULL) return NULL;
        slow = new ListNode(0, head);

        while(slow != NULL && fast != NULL){
            if(slow==fast){
                node = slow -> val;
                break;
            }
            slow = slow -> next;
            fast = fast -> next;
        }

            while(head!= NULL){
                if(head == slow){
                    return head;
                }
                head = head -> next;
            }
        return NULL;
    }
};