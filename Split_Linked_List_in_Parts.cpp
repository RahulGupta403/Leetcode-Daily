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
public:
    int count(ListNode* head){
        if(head==NULL){
            return 0;
        }
        int len=0;
        while(head!=NULL){
            head=head->next;
            len++;
        }
    return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);
        // Base Case Check UP
        if(head==NULL){
            return ans;
        }
        // Base Case Check UP
        if(k==0){
            ans.push_back(head);
            return ans;
        }
        int len=count(head);
        ListNode* curr=head;
        ListNode* prev=NULL;
        int eachBucket=len/k;
        int extraNodes=len%k;
        for(int i=0;i<k;i++){
            ans[i]=curr;
            for(int count=1;count<=len/k + (extraNodes>0?1:0);count++){
                prev=curr;
                curr=curr->next;
            }
            if(prev!=NULL)
               prev->next=NULL;
            extraNodes--;
        }
        return ans;        
    }
};
