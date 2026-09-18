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
    void mergee(ListNode* list1, ListNode* list2,ListNode* merge)
   {
     if(list2==NULL)
    {
        merge->next=list1;
        return;
        
    }
    if(list1==NULL)
    {
        merge->next=list2;
        return;
        
    }
    if(list1->val<list2->val)
    {
        merge->next=list1;
        mergee(list1->next,list2,merge->next);
    }
    else
    {
        merge->next=list2;
        mergee(list1,list2->next,merge->next);
    }

   
   }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-1);
        
        mergee(list1,list2,dummy);
        return dummy->next;
    }
};