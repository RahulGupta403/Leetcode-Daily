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
       if(head==NULL){
           return head;
       }          
    //Insert the node in between the linked list
    Node* curr=head;
    while(curr){
        Node* currNext=curr->next;
        curr->next=new Node (curr->val);
        curr->next->next=currNext;

        curr=currNext;
    }

    // Make the deep copy of the pointers
    curr=head;
    while(curr and curr->next){
        if(curr->random==nullptr){
            curr->next->random=NULL;
        }
        else{
            curr->next->random=curr->random->next;
        }
        curr=curr->next->next;
    }

    //  Seperate the linked list formed
    Node* newHead=head->next;
    Node* newCurr=head->next;
    curr=head;
    while(curr and newCurr){
        if(curr->next!=NULL){
            curr->next=curr->next->next;
        }else{
            curr->next=NULL;
        }
        if(newCurr->next!=NULL){
            newCurr->next=newCurr->next->next;
        }else{
            newCurr->next=NULL;
        }
        curr=curr->next;
        newCurr=newCurr->next;
    }
    return newHead;
    }
};
