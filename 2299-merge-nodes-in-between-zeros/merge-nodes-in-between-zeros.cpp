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
        vector<int> arr;
        int sum = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            if(temp->val == 0 && temp!=head)
            {
                arr.push_back(sum);
                sum = 0;
            }
            else
            {
                sum += temp->val;
            }
            temp = temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* newly = dummy;
        for(int i=0; i<arr.size(); i++)
        {
            ListNode* newnode = new ListNode(arr[i]);
            dummy->next = newnode;
            dummy = dummy->next;
        }
        return newly->next;
        
    }
};