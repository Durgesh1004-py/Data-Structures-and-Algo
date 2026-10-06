class Solution {
public:

    void reverseLL(ListNode* temp, int n)
    {
        // First node of the group
        ListNode* first = temp->next;

        ListNode* prev = temp;
        ListNode* curr = temp->next;

        for(int i = 0; i < n; i++)
        {
            ListNode* nexti = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nexti;
        }

        // Connect previous part to new first node
        temp->next = prev;

        // 'first' is now the last node of the
        // reversed group.
        first->next = curr;
    }


    ListNode* reverseEvenLengthGroups(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        // Group 1 is always of size 1,
        // so no reversal is needed.
        ListNode* temp = head;

        // Start from group 2
        int n = 2;

        while(temp->next != NULL)
        {
            // First node of current group
            ListNode* first = temp->next;

            // Find actual size of current group
            ListNode* curr = first;
            int cnt = 0;

            while(curr != NULL && cnt < n)
            {
                cnt++;
                curr = curr->next;
            }

            // Reverse if actual size is even
            if(cnt % 2 == 0)
            {
                reverseLL(temp, cnt);

                // Original first node is now the
                // last node of the reversed group
                temp = first;
            }
            else
            {
                // Move temp to the last node
                // of the current group
                for(int i = 0; i < cnt; i++)
                {
                    temp = temp->next;
                }
            }

            n++;
        }

        return head;
    }
};