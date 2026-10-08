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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* startConnect = list1;
        ListNode* endConnect = list1;
        while(b!=0)
        {
            endConnect = endConnect->next;
            b-=1;
        }
        endConnect = endConnect->next;

        while(a!=1)
        {
            startConnect = startConnect->next;
            a-=1;
        }
        startConnect->next = list2;
        
        ListNode* temp = list1;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = endConnect;

        return list1;
    }
};