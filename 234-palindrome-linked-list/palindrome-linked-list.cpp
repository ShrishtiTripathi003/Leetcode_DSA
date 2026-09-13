class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL)
        {
            return true;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        // Find middle
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Decide where second half starts
        ListNode* second;

        if(fast != NULL)          // odd length
        {
            second = slow->next;  // skip middle
        }
        else                      // even length
        {
            second = slow;
        }

        // Reverse first half
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != slow)
        {
            ListNode* nex = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        // Compare
        ListNode* first = prev;

        while(first != NULL && second != NULL)
        {
            if(first->val != second->val)
            {
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};