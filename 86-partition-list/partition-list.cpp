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
    ListNode* partition(ListNode* head, int x) {
        vector<int> low;
        vector<int> rest;
        ListNode* temp = head;
        
        while(temp)
        {
            if(temp->val < x)
            {
                low.push_back(temp->val);
            }
            else{
                rest.push_back(temp->val);
            }
            temp = temp->next;
        }
        ListNode* newlow = new ListNode(-1);
        ListNode* newHead = newlow;
        int n1 = low.size();
        
        int i=0;
        while(i<n1)
        {
            ListNode* h1 = new ListNode(low[i]);
            newlow->next = h1;
            newlow = newlow->next;
            i++;
        }
        newlow->next = NULL;

        ListNode* newrest = new ListNode(-1);
        ListNode* restbegin = newrest;
        int n2 = rest.size();
        int j = 0;
        while(j<n2)
        {
            ListNode* h1 = new ListNode(rest[j]);
            newrest->next = h1;
            newrest = newrest->next;
            j++;            
        }
        newlow->next = restbegin->next;
        return newHead->next;
        
    }
};