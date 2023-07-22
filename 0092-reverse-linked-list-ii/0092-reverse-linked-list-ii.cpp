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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* curr=head;
        ListNode* front_link=NULL;
        ListNode* last_link=NULL;
        ListNode* temp;
        ListNode* prev=NULL;
        bool range_entered=false;
        int count=0;
        while(curr!=NULL && count<right){
            count++;
            if(count>=left){
                if(range_entered==false){
                    if(prev!=NULL){
                        front_link=prev;
                    }
                    last_link=curr;
                    range_entered=true;
                }
                temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        last_link->next=curr;
        if(front_link==NULL){
            return prev;
        }
        front_link->next=prev;
        return head;
    }
};