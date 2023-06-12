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
    void reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* forwd = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            forwd = curr -> next;
            curr ->next = prev;
            prev = curr;
            curr = forwd;
        }
        head = prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        int carry = 0, sum = 0;
        while(l1 != NULL && l2  != NULL){
            sum = l1 -> val + l2 -> val + carry;
            temp -> val = (sum % 10);
            carry = sum/10;
            l1 = l1 -> next; 
            l2 = l2 -> next;
            if( l1 != NULL && l2  != NULL ){
                temp -> next = new ListNode(0); 
                temp = temp -> next; 
            }
            
        }
        
        while( l1 != NULL){
            temp-> next  = new ListNode(0);
            temp = temp -> next; 
            sum = l1 -> val + carry;
            temp -> val = sum % 10 ;
            carry = sum / 10;
            l1 = l1 -> next;
        }
        while(l2 != NULL){
            temp-> next  = new ListNode(0);
            temp = temp -> next; 
            sum = l2 -> val + carry;
            temp -> val = sum % 10 ;
            carry = sum / 10;
            l2 = l2 -> next;
        }
        if(carry != 0){
            temp-> next  = new ListNode(0);
            temp = temp -> next; 
            temp -> val = carry;
        }
        temp = NULL;
        return ans;
    }
};