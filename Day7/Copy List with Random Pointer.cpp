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
    private:
    void insertAtTail(Node* &clnHead, Node* &clnTail, int d){
        Node* newN = new Node(d);
        if(clnHead==NULL || clnTail==NULL){
            clnHead= newN;
            clnTail= newN;
        }
        clnTail->next = newN;
        clnTail = clnTail -> next;
    }
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        Node* clnHead= NULL;
        Node* clnTail = NULL;

        while(temp!= NULL){
            insertAtTail(clnHead, clnTail, temp->val);
            temp = temp -> next;
        }

        Node* orgNode = head;
        Node* clnNode = clnHead;
        temp = NULL;
        while(orgNode!= NULL && clnNode != NULL){          
            temp = orgNode -> next;
            orgNode-> next = clnNode;
            orgNode = temp;

            temp = clnNode->next;
            clnNode -> next= orgNode;
            clnNode = temp;            
        }
        
        temp = head;
        while(temp != NULL ){  
            if(temp-> random != NULL){

            temp-> next-> random = temp -> random -> next;
            }
            temp = temp -> next -> next;
        }

        clnNode = clnHead;
        temp = head;
        while(temp && clnNode){
            temp -> next = clnNode -> next;
            if(clnNode -> next){
                clnNode -> next = clnNode -> next -> next;
                clnNode = clnNode -> next;
            }
            temp = temp -> next;
        }

        return clnHead;
    }
};