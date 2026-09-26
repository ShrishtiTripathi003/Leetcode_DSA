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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == NULL || head->next == NULL ||
            head->next->next == NULL)
            return {-1, -1};
        ListNode* curr=head->next;
        ListNode* nex=curr->next;
        ListNode* prev=head;
        vector<int> arr;
        int i=1;
        while(nex!=NULL)
        {
            if((curr->val<nex->val && curr->val<prev->val)||
            (curr->val>nex->val && curr->val>prev->val))
            {
                arr.push_back(i);
            }
            curr=curr->next;
            nex=nex->next;
            prev=prev->next;
            i++;

        }
        
        if(arr.size()<2)
        {
            return {-1,-1};
        }
        int maxi=arr.back()-arr.front();
        int mini=INT_MAX;
        for(int i=1;i<arr.size();i++)
        {
            mini=min(mini,arr[i]-arr[i-1]);
        }
        return {mini,maxi};
    }
};