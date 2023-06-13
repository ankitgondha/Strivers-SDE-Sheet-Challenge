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
    private:
    int len(ListNode* head){
        int length = 0;
        while(head !=0){
            head= head->next;
            length++;
        }
        return length;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
        if(head==NULL || head->next == NULL) return head;

        //reverse first k nodes
        ListNode* prev= NULL;
        ListNode* curr= head;
        ListNode* forwd= NULL;
        int cnt=0;

        while(curr != NULL && cnt<k){
            forwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forwd;
            cnt++;
        }
        
        if(len(curr)<k){
            head->next = curr;
            return prev;
        }

        //recursion
        if(forwd != NULL ){
            head->next=  reverseKGroup(forwd, k);
        }        

        return prev;
        
    }
};