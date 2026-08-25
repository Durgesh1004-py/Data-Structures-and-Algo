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
    ListNode* sortList(ListNode* head) {
        vector<int> vals;
        ListNode* temp= head;
        while(temp)
        {
            vals.push_back(temp->val);
            temp = temp->next;
        }

        sort(vals.begin(), vals.end());

        ListNode* h1 = new ListNode(-1);
        ListNode* newHead = h1;

        for(int i=0; i<vals.size(); i++)
        {
            ListNode* h2 = new ListNode(vals[i]);
            h1->next = h2;
            h1 = h1->next;
        }
        return newHead->next;



        
    }
};