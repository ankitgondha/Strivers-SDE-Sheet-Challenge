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
    ListNode* merge(ListNode* first, ListNode* sec) {
        if(first-> next == NULL){
            first-> next= sec;
            return first;
        }
        ListNode* curr1 = first;
        ListNode* curr2 = sec;
        ListNode* next1 = first->next;
        ListNode* next2 = sec->next;

        while(next1 != NULL && curr2 != NULL ){
            if((curr1 -> val <= curr2-> val) && (next1-> val >= curr2->  val)){
                curr1-> next= curr2;
                next2= curr2 -> next;
                curr2 -> next = next1;
                curr1 = curr2;
                curr2 = next2;

            }

            else{
                curr1 = curr1 -> next;
                next1 = next1 -> next;
                
                if(next1== NULL){
                    curr1-> next = curr2;
                    return first;
                }
            }
        }
        return first;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1== NULL && list2== NULL)
            return NULL;
        else if(list1== NULL)
            return list2; 
        else if(list2== NULL)
            return list1; 

        if(list1-> val <= list2-> val)
            return merge(list1, list2);
        else
            return merge(list2, list1);

        
    }
};