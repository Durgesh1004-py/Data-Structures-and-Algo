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

        vector<int> arr = {-1, -1};

        if(head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return arr;
        }

        ListNode* back = head;
        ListNode* mid = head->next;
        ListNode* front = head->next->next;

        vector<int> ans;

        int cnt = 2;

        while(front != NULL)
        {
            if((back->val > mid->val && mid->val < front->val) ||
               (back->val < mid->val && mid->val > front->val))
            {
                ans.push_back(cnt);
            }

            back = mid;
            mid = front;
            front = front->next;
            cnt++;
        }

        int n1 = ans.size();

        // 0 or 1 critical point
        if(n1 < 2)
            return arr;

        int mindis = INT_MAX;

        for(int i = 1; i < n1; i++)
        {
            mindis = min(mindis, ans[i] - ans[i-1]);
        }

        int maxdis = ans[n1-1] - ans[0];

        return {mindis, maxdis};
    }
};