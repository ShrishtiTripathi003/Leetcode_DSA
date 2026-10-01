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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* first=head;
        //reversing 2 nd half from slow to fast
        ListNode* curr=slow;
        ListNode* prev=NULL;
        while(curr!=NULL)
        {
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        ListNode* second=prev;
        int maxi=INT_MIN;
        while(second!=NULL)
        {
            int sum=second->val+first->val;
            maxi=max(maxi,sum);
            second=second->next;
            first=first->next;
        }
        return maxi;
    }
};