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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* waste = new ListNode();
        ListNode* head=waste;
        int sum=0,temp=0;
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL){
                temp+=(l1->val);
                l1=l1->next;
            }
            if(l2!=NULL){
                temp+=(l2->val);
                l2=l2->next;
            }
            temp+=sum;
            if(temp>9){
                sum=1;
                ListNode* newnode= new ListNode(temp%10);
                head->next=newnode;
                head=newnode;
            }
            else{
                sum=0;
                ListNode* newnode =new ListNode(temp);
                head->next=newnode;
                head=newnode;
            }
            temp=0;
            
        }
        if(sum==1){
            ListNode* newnode=new ListNode(1);
            head->next=newnode;
            head=newnode;
        }
        return waste->next;
    }
};