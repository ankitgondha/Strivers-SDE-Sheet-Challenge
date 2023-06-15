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
    int getLen(ListNode* head){
        int cnt = 0;
        while(head != NULL){
            head= head -> next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head-> next == NULL){
            return head;
        }
        int len= getLen(head);
        k = k % len;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(k){
            while(temp -> next != NULL){
                prev =temp;
                temp = temp -> next;
            }
                temp -> next = head;
                head = temp;
                prev -> next = NULL;
            
            k--;
        }
        return head;
    }
};