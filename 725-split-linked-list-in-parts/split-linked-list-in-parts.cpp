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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>v(k);

        int size=0;
        ListNode* curr=head;

        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
        int split=size/k;
        int remain=size%k;

        curr=head;
        ListNode* prev=curr;

        for(int i=0;i<k;i++){
            ListNode* newn=curr;
            int currsize=split;
            if(remain>0){
                remain--;
                currsize++;
            }

            int j=0;
            while(j<currsize){
                prev=curr;
                if(curr!=NULL){
                    curr=curr->next;
                }
                j++;
            }

            if(prev!=NULL){
                prev->next=NULL;
            }
            v[i]=newn;
        }
        return v;
    }
};