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
    ListNode* findMiddle(ListNode* &head){
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    ListNode* findReverse( ListNode* &head){
        ListNode* prev = NULL;
        ListNode* forwd = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            forwd = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forwd;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL)
            return 1;
        //find the middle
        ListNode* mid = findMiddle(head);
        ListNode* rev = findReverse(mid->next);

        while(rev != NULL){
            if(head -> val != rev -> val){
                return false;
            }
            head = head -> next;
            rev = rev -> next;
        }
        return 1;
    }
};