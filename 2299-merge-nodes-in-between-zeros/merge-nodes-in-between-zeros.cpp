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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* dummy=new ListNode(0);
        ListNode* arr=dummy;
        while(temp!=NULL)
        {
            int sum=0;
            while(temp->val!=0)
            {
               sum=sum+temp->val;
               temp=temp->next; 
            }
            if(sum!=0)
            {
                arr->next=new ListNode(sum);
                arr=arr->next;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};